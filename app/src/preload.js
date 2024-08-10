const { ipcRenderer } = require('electron');

function listener() {
    document.addEventListener('keypress', function (e) {
        if (e.key === 'Enter') {
            let txtBox = document.getElementById('userInput');

            if (document.activeElement === txtBox) {
                const userInput = document.getElementById('userInput');
                const output = document.getElementById('output');
                const command = userInput.value.trim();

                let txtval = txtBox.value;
                ipcRenderer.send('saveText', txtval);

                if (command){
                    const newLine = document.createElement('div');
                    newLine.textContent = command;

                    output.appendChild(newLine);
                }
                txtBox.value = '';
            }
        }

        document.getElementById('userInput').addEventListener('keydown', handleInput);
    });
}

listener();

