const { app, BrowserWindow, ipcMain } = require('electron');
const path = require('path');

var fs = require('fs');
var filePath = path.join(__dirname, '../execute/cmd.txt');

function createWindow(){
    const win = new BrowserWindow({
        width: 1200,
        height: 720,
        webPreferences: {
            nodeIntegrationInWorker: true,
            contextIsolation: true,
            nodeIntegration: true,
            webviewTag: true,
            preload: path.join(__dirname, 'preload.js'),
        }
    })

    win.loadFile(path.join(__dirname, './render/index.html'));
}

app.whenReady().then(() => 
    createWindow(),
);

ipcMain.on('saveText', (event, text) => {
    fs.writeFile(filePath, text, (err) => {
        if (err)
            console.log(err);
    });
});

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});

