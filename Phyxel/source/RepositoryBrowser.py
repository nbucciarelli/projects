#
# File containing all code that defines the repository browser
#

import wx
import os.path, dircache


class RepositoryBrowser( wx.Frame ):
    def __init__(self, *args, **kwds):
        # Parent constructor
        wx.Frame.__init__( self, *args, **kwds )
        
        
        # Create the file menu
        self._initMenuBar()
        
        #self.buildTree( 'C:/Users/Kyle/Documents/Code' )
        
        
    def _initMenuBar(self):
        """ Initialize the file menu """
        # create file menu
        fileMenu = wx.Menu()
        fileMenu.Append( wx.ID_OPEN, "&Open", " Open repository" )
        fileMenu.AppendSeparator()
        fileMenu.Append( wx.ID_EXIT, "E&xit", " Terminate Phyxel" )
        
        # create menu bar
        self.menuBar = wx.MenuBar()
        self.menuBar.Append( fileMenu, "&File" )
        
        # link press events
        wx.EVT_MENU( self, wx.ID_EXIT, self.onExit )
        wx.EVT_MENU( self, wx.ID_OPEN, self.onOpen )
        
        # hook menu bar to frame
        self.SetMenuBar( self.menuBar )
        
        
    def _initTreeView(self, rootPath):
        """ Initialize the tree view """
        
        # The tree object
        self.tree = wx.TreeCtrl( self, -1, style=wx.TR_HAS_BUTTONS | wx.TR_DEFAULT_STYLE | wx.SUNKEN_BORDER )
        self._buildTree( rootPath )
        
        # Add tree object to frame
        sizer = wx.BoxSizer( wx.VERTICAL )
        sizer.Add( self.tree, 1, wx.EXPAND, 0 )
        self.SetAutoLayout( True )
        self.SetSizer( sizer )
        #sizer.Fit( self )
        #sizer.SetSizeHints( self )
        self.Layout()
        
        # register for the self.onExpand function
        wx.EVT_TREE_ITEM_EXPANDING( self.tree, self.tree.GetId(), self.onExpand )
        wx.EVT_TREE_ITEM_ACTIVATED( self.tree, self.tree.GetId(), self.onActivated )
        
        


    def _buildTree(self, rootDir):
        """ Build the first tier of the tree given the root """
        self.rootId = self.tree.AddRoot( rootDir )
        self.tree.SetPyData( self.rootId, ( rootDir, 1 ) )
        self._extendTree( self.rootId )
        self.tree.Expand( self.rootId )
            
            
    def _extendTree(self, parentId):
        """
        Recursive function used to expand the tree from root.
        """
        # Get the absolute path of the parent
        parentDir = self.tree.GetPyData( parentId )[0]
        
        # Iterate through child directories
        dirs = dircache.listdir( parentDir )
        dirs.sort()
        for child in dirs:
            childPath = os.path.join( parentDir, child )
            
            # Add child to the parent
            childId = self.tree.AppendItem( parentId, child )
            
            # Link full child path with its entry
            self.tree.SetPyData( childId, ( childPath, False ) )
                
            # if its a directory recurse
            if os.path.isdir( childPath ) and not os.path.islink( child ):
                self._extendTree( childId )
                    
        
    def onExpand(self, event):
        """
        onExpand will be called when the user expands a tree node.
        This will build out our tree.
        """
        # Get the wxID of the expanded item and ensure its valid.
        itemId = event.GetItem()
        if not itemId.IsOk():
            itemId = self.tree.GetSelection()
            
        # If not previously expanded then build tree.
        oldData = self.tree.GetPyData( itemId )
        if oldData[1] == False:
            self.tree.DeleteChildren( itemId )
            self._extendTree( itemId )
            self.tree.SetPyData( itemId, ( oldData[0], True ) )
            
    def onActivated(self, event):
        """
        onActivated will be called when the user double clicks a file
        This will determine what control to open to correspond with selected file
        """
        # Get the wxID of the activated item and ensure its valid.
        itemId = event.GetItem()
        if not itemId.IsOk():
            itemId = self.tree.GetSelection()
            
        path = self.tree.GetPyData( itemId )[0]
        frame = wx.Frame( None, wx.ID_ANY, str( path ) )
        frame.Show( True )
    
    
    def onOpen(self, event):
        """
        hit when the open option is chosen from the file menu
        """
        dlg = wx.DirDialog( self, "Select Repository Root", '') # parentWindow, Test, defaultPath ( save the last to make it open to the same one every time )
        if dlg.ShowModal() == wx.ID_OK:
            self._initTreeView( dlg.GetPath() )
        
        
    def onExit(self, event):
        """ Hit when the exit option is chosen from the menu bar """
        self.Close( True )
