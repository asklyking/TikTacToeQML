import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

Dialog {
    id: dialogInputConnectionInfo
    title: "Please input Connection imformation"
    visible: true
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    modality: Qt.WindowModal
    width: 350
    height: 150

    signal inactivedLoader()

    Text {
        id: txtServerIP
        text: qsTr("Server Ipaddress")
        anchors.verticalCenter: txteditServerIP.verticalCenter
        anchors.right: txteditServerIP.left
        anchors.rightMargin: 15
    }

    TextEdit {
        id: txteditServerIP
        text: qsTr("192.168.100.11")
        width: 150
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.topMargin: 5
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
            radius: 5
        }
    }

    Text {
        id: txtServerPort
        text: qsTr("Server Port")
        anchors.verticalCenter: txteditServerPort.verticalCenter
        anchors.right: txteditServerPort.left
        anchors.rightMargin: 15
    }

    TextEdit {
        id: txteditServerPort
        width: 150
        verticalAlignment: Text.AlignVCenter
        anchors.top: txteditServerIP.bottom
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.topMargin: 25
        Rectangle {
            id: rectCoverTxtEditPort
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
            radius: 5
        }
    }

    onRejected: {
        dialogInputConnectionInfo.inactivedLoader()
    }

    onAccepted: {
        dialogInputConnectionInfo.inactivedLoader()
        gameController.startOnlineGame(txteditServerIP.text, txteditServerPort.text);
    }

    onVisibleChanged: {
        if(!dialogInputConnectionInfo.visible){
            dialogInputConnectionInfo.inactivedLoader()
        }
    }
}
