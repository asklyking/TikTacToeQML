import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

Dialog {
    id: dialogMenuReplay
    title: "Please choose a game to replay"
    standardButtons: "NoButton"
    visible: true
    width: 350
    height: 150

    signal inactivedLoader()

    ListView {
        anchors.fill: parent
        spacing : 2

        model: listGameReplay
        delegate: Rectangle {
            width: parent.width
            height: 20
            color: "lightgray"
            Text {
                id: txtGameTitle
                anchors.centerIn: parent
                text: game_title
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    dialogMenuReplay.inactivedLoader()
                    gameController.replaySelectedGame(index)
                }
            }
        }
    }

    onVisibleChanged: {
        if(!dialogMenuReplay.visible){
            dialogMenuReplay.inactivedLoader()
        }
    }
}
