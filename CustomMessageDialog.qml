import QtQuick 2.0
import QtQuick.Dialogs 1.2

//MessageDialog {
//    id: dialogMessage
//    title: "Notification"
//    text: "End game!!!!!"
//    onAccepted: {
//        Qt.quit()
//    }

//    visible : (gameController.currentGameState == 99) ? false : true
//}

Rectangle {
    id: rectBackground
    anchors.fill: parent
    color: 'transparent'

    Rectangle {
        id: dialogMessage
        anchors.centerIn: parent
        width: 200
        height: 100
        radius: 10
        color: 'lightgray'
        border {
            width: 1
            color: 'red'
        }

        Rectangle{
            id: rectMessageArea
            height: dialogMessage.height / 2
            width: dialogMessage.width
            color: 'transparent'
            border {
                width: 1
                color: 'transparent'
            }

            Text {
                id: txtMessage
                text: qsTr("End game!!!!")
                anchors.centerIn: parent

                states: [
                    State {
                        name: "Player1Win"
                        when: gameController.currentGameState == 1
                        PropertyChanges {
                            target: txtMessage
                            text: qsTr("Player 1 win")
                        }
                    },

                    State {
                        name: "Player2Win"
                        when: gameController.currentGameState == -1
                        PropertyChanges {
                            target: txtMessage
                            text: qsTr("Player 2 win")
                        }
                    },

                    State {
                        name: "Draw"
                        when: gameController.currentGameState == 0
                        PropertyChanges {
                            target: txtMessage
                            text: qsTr("Draw game")
                        }
                    }
                ]
            }
        }



        Rectangle {
            id: btnOK
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rectMessageArea.bottom
            anchors.topMargin: 10
            width: 50
            height: 25
            radius: 5
            border {
                width: 1
                color: 'black'
            }

            Text {
                anchors.centerIn: parent
                text: qsTr("OK")
            }
        }
    }

    MouseArea {
        id: mouseareaBackground
        anchors.fill: parent
        onClicked: {
            var globalX = btnOK.x + dialogMessage.x + rectBackground.x
            var globalY = btnOK.y + dialogMessage.y + rectBackground.y
            if(mouseX > globalX
                    && mouseX < globalX + btnOK.width
                    && mouseY > globalY
                    && mouseY < globalY + btnOK.height){
                gameController.clickedBtnReset();
            }
        }
    }
}
