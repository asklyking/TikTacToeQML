import QtQuick 2.0

Item {
    property string txtCellLabel : ""

    width: 40
    height: 40

    Rectangle {
        id: rect
        width: 40
        height: 40
        radius: 10

        border {
            color: "gray"
            width: 1
        }

        color: "white"
        Text {
            id: txtLabelItem
            text: txtCellLabel
            anchors.centerIn: parent

            states: [
                State {
                    name: "changeToRedColor"
                    when: txtLabelItem.text == "X"
                    PropertyChanges { target: txtLabelItem; color:"red"}
                },
                State {
                    name: "changeToBlueColor"
                    when: txtLabelItem.text == "O"
                    PropertyChanges { target: txtLabelItem; color:"blue"}
                }
            ]
        }
    }

//    MouseArea {
//        id: mouseArea
//        anchors.fill: rect

//        onClicked: {
//            gameController.clickedGameCell(index);
//        }
//    }

    states: [
        State {
            name: "inDrag"
            when: index == gridviewGameBoard.draggedItemIndex
            PropertyChanges { target: rect; parent: dragContainer }
            PropertyChanges { target: rect; anchors.centerIn: undefined }
            PropertyChanges { target: rect; x: gridviewMouseArea.mouseX - rect.width / 2 }
            PropertyChanges { target: rect; y: gridviewMouseArea.mouseY - rect.height / 2 }
        }
    ]
}
