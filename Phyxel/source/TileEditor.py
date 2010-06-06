#
# Define the Tile Editor control
#

import wx

from os import getcwd

TILE_MAP_FRAME_WIDTH = 1200
TILE_MAP_FRAME_HEIGHT = 900
CONTROL_PANEL_WIDTH = 350
MAP_PANEL_WIDTH = TILE_MAP_FRAME_WIDTH - CONTROL_PANEL_WIDTH

TE_ID_PAINT = 1
TE_ID_BUCKET = 2
TE_ID_STAMP = 3
TE_ID_FILL = 4

TE_ID_OPEN_TILESHEET = 50

TE_ID_SAVE = 101
TE_ID_EXIT = 102

class TileMap( wx.Frame ):
	def __init__(self, *args, **kwds):
		# Parent constructor
		wx.Frame.__init__( self, size=(TILE_MAP_FRAME_WIDTH, TILE_MAP_FRAME_HEIGHT), *args, **kwds )
	
		# init controls
		self._initMenuBar()
		self._initPanels()
		
		# init data
		self.tileWidth = 32
		self.tileHeight = 32
		

	def _initMenuBar(self):
		""" Initialize the menu bar """
		
		# create file menu
		fileMenu = wx.Menu()
		saveItem = fileMenu.Append( TE_ID_SAVE, "&Save", " Save Map" )
		fileMenu.AppendSeparator()
		closeItem = fileMenu.Append( TE_ID_EXIT, "&Close", " Close Map Editor" )
		
		# create tile selector options
		tileSelectorMenu = wx.Menu()
		openTileSheetItem = tileSelectorMenu.Append( TE_ID_OPEN_TILESHEET, "&Open Tilesheet", " Open a new tile sheet" )
		
		# create menu bar
		menuBar = wx.MenuBar()
		menuBar.Append( fileMenu, "&File" )
		menuBar.Append( tileSelectorMenu, "&Tile Selector" )
		
		# link menu events
		self.Bind( wx.EVT_MENU, self.onSave, saveItem )
		self.Bind( wx.EVT_MENU, self.onClose, closeItem )
		self.Bind( wx.EVT_MENU, self.onOpenTileSheet, openTileSheetItem )
		
		self.SetMenuBar( menuBar )

	def _initPanels(self):
		# The Panels
		self.controlsPanel = ControlsPanel( self )
		self.mapPanel = MapPanel( self )
		self.tileSelectorPanel = TileSelectorPanel( self )

		vertSizer = wx.BoxSizer( wx.VERTICAL )
		vertSizer.Add( self.controlsPanel, 550, wx.EXPAND )
		vertSizer.Add( self.tileSelectorPanel, 350, wx.EXPAND )
		
		sizer = wx.BoxSizer( wx.HORIZONTAL )
		sizer.Add( vertSizer, CONTROL_PANEL_WIDTH, wx.EXPAND )
		sizer.Add( self.mapPanel, MAP_PANEL_WIDTH, wx.EXPAND )
		self.SetSizer( sizer )

	def onSave(self, event):
		pass
	
	def onClose(self, event):
		self.Close( True )
		
	def onOpenTileSheet(self, event):
		dlg = wx.FileDialog( self, "Select Tile Sheet", getcwd(), '', '*.*', wx.OPEN )
		if dlg.ShowModal() == wx.ID_OK:
			self.tileSelectorPanel.setTileSheet( dlg.GetPath() )
		dlg.Destroy()


class ControlsPanel( wx.Panel ):
	def __init__(self, parent):
		# Parent Constructor
		wx.Panel.__init__( self, parent, wx.ID_ANY, style=wx.SIMPLE_BORDER )
		
		# Add some controls
		drawingControlsSizer = self._initDrawingControls()
		self.SetSizer( drawingControlsSizer )
		
	def _initDrawingControls(self):		
		# Create buttons
		self._paintButton = wx.ToggleButton( self, TE_ID_PAINT, 'Paint' )
		self._bucketButton = wx.ToggleButton( self, TE_ID_BUCKET, 'Bucket' )
		self._stampButton = wx.ToggleButton( self, TE_ID_STAMP, 'Stamp' )
		self._fillButton = wx.ToggleButton( self, TE_ID_FILL, 'Fill' )
		
		# bind to click events
		self.Bind( wx.EVT_TOGGLEBUTTON, self.onPaintPressed, self._paintButton )
		self.Bind( wx.EVT_TOGGLEBUTTON, self.onBucketPressed, self._bucketButton )
		self.Bind( wx.EVT_TOGGLEBUTTON, self.onStampPressed, self._stampButton )
		self.Bind( wx.EVT_TOGGLEBUTTON, self.onFillPressed, self._fillButton )
		
		# add to sizer
		sizer = wx.BoxSizer( wx.VERTICAL )
		sizer.Add( self._paintButton, 1 )
		sizer.Add( self._bucketButton, 1 )
		sizer.Add( self._stampButton, 1 )
		sizer.Add( self._fillButton, 1 )
		
		self.onPaintPressed( None )
		
		return sizer

	def onPaintPressed(self, event):
		self._paintButton.SetValue( True )
		self._bucketButton.SetValue( False )
		self._stampButton.SetValue( False )
		self._fillButton.SetValue( False )
		
		self.Parent.activeDrawTool = TE_ID_PAINT

	def onBucketPressed(self, event):
		self._paintButton.SetValue( False )
		self._bucketButton.SetValue( True )
		self._stampButton.SetValue( False )
		self._fillButton.SetValue( False )
		
		self.Parent.activeDrawTool = TE_ID_BUCKET

	def onStampPressed(self, event):
		self._paintButton.SetValue( False )
		self._bucketButton.SetValue( False )
		self._stampButton.SetValue( True )
		self._fillButton.SetValue( False )
		
		self.Parent.activeDrawTool = TE_ID_STAMP

	def onFillPressed(self, event):
		self._paintButton.SetValue( False )
		self._bucketButton.SetValue( False )
		self._stampButton.SetValue( False )
		self._fillButton.SetValue( True )
		
		self.Parent.activeDrawTool = TE_ID_FILL
		
		
class TileSelectorPanel( wx.ScrolledWindow ):
	def __init__(self, parent):
		# Parent constructor
		wx.ScrolledWindow.__init__( self, parent, wx.ID_ANY, style=wx.SIMPLE_BORDER )
		
		self.Parent.tileSheet = None
		self.Parent.selectedTile = None
		
		self.Bind( wx.EVT_PAINT, self.onPaint )
		self.Bind( wx.EVT_LEFT_UP, self.onLeftMouseRelease )
		
	def setTileSheet(self, filePath):
		tileSheet = wx.Bitmap( filePath )
		width = tileSheet.GetWidth()
		height = tileSheet.GetHeight()
		self.SetScrollbars( 20, 20, width/20, height/20)
		
		self.Parent.tileSheet = tileSheet
		self.Parent.selectedTile = 0
		
	def onLeftMouseRelease(self, event):
		# calculate the x, y position of the mouse click on the image
		# this takes into account the scroll bars.
		x, y = event.GetPositionTuple()
		offSetx, offSety = self.CalcScrolledPosition( 0, 0 )
		x, y = x - offSetx, y - offSety
		
		# calculate the selected tile.
		# it may be beneficial to pull some of this code into a helper function.
		# tiles follow the pattern
		# 0, 1, 2, 3, 4
		# 5, 6, 7, 8, 9...
		xTile = x / self.Parent.tileWidth
		yTile = y / self.Parent.tileWidth
		tilesWide = self.Parent.tileSheet.GetWidth() / self.Parent.tileWidth
		self.Parent.selectedTile = yTile * tilesWide + xTile
		
		# Ensure the selected tile gets highlighted
		self.Refresh()
		
	def onPaint(self, event):
		ts = self.Parent.tileSheet
		if ts is not None:
			# get dc
			dc = wx.PaintDC( self )
			
			# draw the tile sheet
			x, y = self.CalcScrolledPosition( 0, 0 )
			dc.DrawBitmap( self.Parent.tileSheet, x, y )
			
			# draw grid
			dc.SetPen( wx.Pen( 'black', 1 ) )
			sheetWidth = ts.GetWidth()
			sheetHeight = ts.GetHeight()
			tileWidth = self.Parent.tileWidth
			tileHeight = self.Parent.tileHeight
			for i in range( int(sheetWidth / tileWidth) + 1 ):
				x1, y1 = self.CalcScrolledPosition( i * tileWidth, 0 )
				x2, y2 = self.CalcScrolledPosition( i * tileWidth, sheetHeight )
				dc.DrawLine( x1, y1, x2, y2 )
			for i in range( int(sheetHeight / tileHeight) + 1 ):
				x1, y1 = self.CalcScrolledPosition( 0, i * tileHeight )
				x2, y2 = self.CalcScrolledPosition( sheetWidth, i * tileHeight )
				dc.DrawLine( x1, y1, x2, y2 )
				
			# highlight selected tile
			st = self.Parent.selectedTile
			if st is not None:
				x1 = ( st % tileWidth ) * tileWidth
				y1 = int (st / tileWidth ) * tileHeight
				x1, y1 = self.CalcScrolledPosition( x1, y1 )
				x2, y2 = x1 + tileWidth, y1 + tileHeight
				dc.SetPen( wx.Pen( 'green', 1 ) )
				dc.DrawLine( x1, y1, x2, y1 )
				dc.DrawLine( x2, y1, x2, y2 )
				dc.DrawLine( x2, y2, x1, y2 )
				dc.DrawLine( x1, y2, x1, y1 )


class MapPanel( wx.Panel ):
	def __init__(self, parent):
		# Parent constructor
		wx.Panel.__init__( self, parent, wx.ID_ANY )
		
		# bind on paint method
		self.Bind( wx.EVT_PAINT, self.onPaint )
		
	def onPaint(self, event):
		"""
		Handle painting
		"""
		dc = wx.PaintDC( self )
		dc.SetPen( wx.Pen( 'black', 1 ) )
		
		for i in range(10):
			dc.DrawLine(0, i * 32, MAP_PANEL_WIDTH, i * 32)
			dc.DrawLine(i * 32, 0, i * 32, 800)