const { app, BrowserWindow, ipcMain, nativeTheme } = require('electron')
const path = require('path')
const WebSocketController = require('./controller/controller');

function createWindow () {
    WebSocketController()
  const win = new BrowserWindow({
    width: 1200,
    height: 800,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  })

  win.loadFile('./dist/AngularFrontend/index.html')
  //win.loadURL('http://localhost:8080');
  win.focus();
  // mainWindow.setFullScreen(true);

  // Open the DevTools.
  win.webContents.openDevTools();

  ipcMain.handle('dark-mode:toggle', () => {
    if (nativeTheme.shouldUseDarkColors) {
      nativeTheme.themeSource = 'light'
    } else {
      nativeTheme.themeSource = 'dark'
    }
    return nativeTheme.shouldUseDarkColors
  })
}

app.whenReady().then(() => {
  createWindow()
})

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})
