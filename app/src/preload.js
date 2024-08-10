const { ipcRenderer } = require('electron');

function listener() {
    document.addEventListener('keypress', function (e) {
        if (e.key === 'Enter') {
            let txtBox = document.getElementById('userInput');

            if (document.activeElement === txtBox) {
                let txtval = txtBox.value;
                ipcRenderer.send('saveText', txtval);

                txtBox.value = '';
            }
        }
    });
}

listener();

