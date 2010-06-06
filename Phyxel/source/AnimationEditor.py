#
# Define the animation editor control
#

import wx

class Animation( wx.Frame ):
	def __init__(self, *args, **kwds):
		# Parent constructor
		wx.Frame.__init__( self, size=(800,600), *args, **kwds )