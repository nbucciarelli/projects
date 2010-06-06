#
# File containing all code that defines the repository browser
#

import wx
import os.path, dircache
from copy import copy

from ControlSelector import getStringFromClass, openControlFromFile, openControl
from ControlSelector import controlDict
from ControlSelector import FILE_ID_MAP


newControlLambdas = {}

class RepositoryBrowser( wx.Frame ):
    def __init__(self, *args, **kwds):
        # Parent constructor
        wx.Frame.__init__( self, *args, **kwds )
        
        # Create the file menu
        self._initMenuBar()

    def _initMenuBar(self):
        """ Initialize the file menu """
        
        # create file menu
        fileMenu = wx.Menu()
        fileMenu.Append( wx.ID_OPEN, "&Open", " Open repository" )
        fileMenu.AppendSeparator()
        fileMenu.Append( wx.ID_EXIT, "E&xit", " Terminate Phyxel" )
        
        for key, value in controlDict.iteritems():
            newControlLambdas[ key ] = lambda e : openControl( key )
        
        #for value in controlDict.itervalues():
        #   value
        
        # create the new menu
        newMenu = wx.Menu()
        for key, value in controlDict.iteritems():
            item = newMenu.Append( key, getStringFromClass( value ), "har" )
            self.Bind( wx.EVT_MENU, self.onNewTileMap, item )
            #newControlLambdas[key] = ((lambda e : openControl( key )), key, value)
            #wx.EVT_MENU( self, key, newControlLambdas[key][0] )
            #lambda e : openControl( copy( key ) )
        
        # create menu bar
        self.menuBar = wx.MenuBar()
        self.menuBar.Append( fileMenu, "&File" )
        self.menuBar.Append( newMenu, "&New" )
        
        # link press events
        wx.EVT_MENU( self, wx.ID_OPEN, self.onOpen )
        wx.EVT_MENU( self, wx.ID_EXIT, self.onExit )
        
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
        
        openControlFromFile( str( path ) )
        
    def onNewTileMap(self, event):
        """
        Hopefully temporery, can we use lambda's to dynamically bind to the
        openControl function and send in the correct id
        """
        openControl( FILE_ID_MAP )

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















