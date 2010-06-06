#
# Helper functions for writing and reading a Phyx Object header chunk
#

from TileEditor import TileMap
from AnimationEditor import Animation
from wx import ID_ANY

FILE_ID_HEADER            = 'PHYXOBJ'
FILE_ID_LENGTH            = 1

FILE_ID_MAP               = 254
FILE_ID_ANIMATION         = 253

controlDict = {
    FILE_ID_MAP : TileMap,
    FILE_ID_ANIMATION : Animation
    }

def getStringFromClass( c ):
	""" Given a class get its name as a string """
	return str( c ).split( '.' )[1].split( "'" )[0]

def openControlFromFile( filePath ):
	"""
	Given a filePath this function will init and open the appropriate control.
	
	New controls should:
	 - be given an ID and added to the controlDict above
	 - have an init like the following 'def __init__(self, *args, **kwds)'
	"""
	fileId = None
	with open( filePath, 'rb' ) as f:
		header = f.read( len( FILE_ID_HEADER ) )
		if header == FILE_ID_HEADER:
			objId = int( f.read( FILE_ID_LENGTH ) )
			
	editor = openControl( objId )
	if editor is not None:
		editor.SetTitle( filePath.split( '\\' )[-1] )
		#editor.load( filePath )

def openControl( objId ):
	"""
	Open the appropriate control given an id
	"""
	if objId is not None and objId in controlDict:
		editor = controlDict[objId]( None, ID_ANY, "New " + getStringFromClass( controlDict[objId] ) )
		editor.Show( True )
		return editor