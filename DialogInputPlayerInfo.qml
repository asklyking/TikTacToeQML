import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

Dialog {
    id: dialogInputPlayerInfo
    title: "Please input Connection imformation"
    visible: true
    standardButtons: StandardButton.Ok | StandardButton.Cancel
    width: 350
    height: 150

    signal inactivedLoader()

    Text {
        id: txtPlayer1Name
        text: qsTr("Player 1")
        anchors.verticalCenter: txteditPlayer1Name.verticalCenter
        anchors.right: txteditPlayer1Name.left
        anchors.rightMargin: 15
    }

    TextEdit {
        id: txteditPlayer1Name
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
        id: txtPlayer2Name
        text: qsTr("Player 2")
        anchors.verticalCenter: txteditPlayer2Name.verticalCenter
        anchors.right: txteditPlayer2Name.left
        anchors.rightMargin: 15
    }

    TextEdit {
        id: txteditPlayer2Name
        width: 150
        verticalAlignment: Text.AlignVCenter
        anchors.top: txteditPlayer1Name.bottom
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.topMargin: 25
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
            radius: 5
        }
    }

    onRejected: {
        dialogInputPlayerInfo.inactivedLoader()
    }

    onAccepted: {
        dialogInputPlayerInfo.inactivedLoader()
        gameController.startOfflineGame(txteditPlayer1Name.text, txteditPlayer2Name.text)
    }

    onVisibleChanged: {
        if(!dialogInputPlayerInfo.visible){
            dialogInputPlayerInfo.inactivedLoader()
        }
    }
}
