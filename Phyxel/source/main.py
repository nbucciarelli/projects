#
# Main file creates the application and start up frames / panels
#

import wx
from RepositoryBrowser import RepositoryBrowser

# create the app
app = wx.App(False)

# create a frame
repositoryBrowser = RepositoryBrowser( None, wx.ID_ANY, "Phyxel", size=(225,650) )

# show the frame
repositoryBrowser.Show(True)

# run the app main loop
app.MainLoop()