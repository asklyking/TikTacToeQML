import QtQuick 2.0

Item {
    anchors.fill: parent

    Text {
        anchors.top: gridviewGameBoard.top
        anchors.topMargin: 20
        anchors.right: gridviewGameBoard.left
        anchors.rightMargin: 10
        id: txtGameStateTilte
        text: qsTr("GAME STATE:")
    }

    Text {
        anchors.top: txtGameStateTilte.bottom
        anchors.topMargin: 20
        anchors.right: gridviewGameBoard.left
        anchors.rightMargin: 10
        id: txtGameState

        states: [
            State {
                name: "Player1Turn"
                when: gameController.isPlayer1Turn
                PropertyChanges {
                    target: txtGameState
                    text: "Turn : Player 1"
                }
            },
            State {
                name: "Player2Turn"
                when: !gameController.isPlayer1Turn
                PropertyChanges {
                    target: txtGameState
                    text: "Turn : Player 2"
                }
            }
        ]
    }

    GridView {
        id : gridviewGameBoard
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        width: 400
        height: 400
        cellWidth: 40
        cellHeight: 40
        interactive: false


        model: gameGridViewModel


        delegate: GameBoardCell {
            txtCellLabel: text
        }

        Item {
            id: dragContainer
            anchors.fill: parent
        }

        property int draggedItemIndex: -1

        MouseArea {
            id: gridviewMouseArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onReleased: {
                if(mouse.button & Qt.RightButton) {
                    if (gridviewGameBoard.draggedItemIndex != -1) {
                        var draggedIndex = gridviewGameBoard.draggedItemIndex
                        if(gridviewGameBoard.indexAt(mouseX, mouseY)){
                            gameController.moveItemInModel(draggedIndex,gridviewGameBoard.indexAt(mouseX, mouseY))
//                            gameGridViewModel.move(draggedIndex,gridviewGameBoard.indexAt(mouseX, mouseY),1)
                        }
                        gridviewGameBoard.draggedItemIndex = -1
                    }
                }
            }
            onPressed: {
                if(mouse.button & Qt.RightButton) {
                    gridviewGameBoard.draggedItemIndex = gridviewGameBoard.indexAt(mouseX, mouseY)
                } else {
                    gameController.clickedGameCell(gridviewGameBoard.indexAt(mouseX, mouseY))
                }
            }
        }

    }

    Loader {
        id : loaderMessageDialog
        source: 'CustomMessageDialog.qml'
        anchors.fill: parent
        active : (gameController.currentGameState == 99) ? false : true
    }
}
