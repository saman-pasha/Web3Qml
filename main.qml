import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import "abi.js" as Abi
import "web3.js" as Web3


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Web3Qml")

    Label {
        id: output
        anchors.fill: parent
        wrapMode: Text.Wrap
        font.pixelSize: 20
        text: "Web3Qml"
    }

    Component.onCompleted: {
        var w3 = new Web3.Web3("https://mianjoo.ir:8545");

        w3.eth.getCoinbase().then(function (coinbase) {
            console.log('Coinbase:', coinbase)
            output.text = output.text + "\nCoinbase: " + coinbase.toString()

            w3.eth.getBalance(coinbase).then(function (balance) {
                console.log('Balance:', balance)
                output.text = output.text + "\nBalance: " + balance.toString()

                var contract = new w3.eth.Contract(Abi.ABI, '0xFD35fCB4096bBfa78ECb41d354894A86BB0E4F8F')
                contract.methods.balanceOf(coinbase).call(
                            {
                                'from': coinbase
                            },
                            function(error, result) {
                                console.log('Smart Contract:', error, result);
                                output.text = output.text + "\nSmart Contract: " + result.toString()
                            });
            });
        })
    }
}
