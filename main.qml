import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    //    width: 640
    //    height: 480
    title: gameController.gameTitle

    maximumHeight: 480
    maximumWidth: 640

    minimumHeight: 480
    minimumWidth: 640

    property string id_menu_replay: "value"
    property string id_input_connection_info : "value"
    property string if_input_player_info : "value"

    menuBar: MenuBar {
        Menu {
            title: "New Game"
            MenuItem {
                text: "Offline"
                shortcut: ""
                onTriggered: {
                    inactiveAllLoader()
                    loaderInputPlayerInfo.active = true
                }
            }
            MenuItem {
                text: "Online"
                onTriggered: {
                    inactiveAllLoader()
                    loaderInputConnectionInfo.active = true
                }
            }
            MenuItem {
                text: "Vs Computer"
                onTriggered: {
                }
            }
            MenuItem {
                text: "Replay"
                onTriggered: {
                    gameController.selectGameToReplay()
                    inactiveAllLoader()
                    loaderMenuReplay.active = true
                }
            }
            MenuItem {
                text: "Quit"
                shortcut: "Ctrl+W"
                onTriggered: {
                    Qt.quit()
                }
            }
        }

        Menu {
            title: "Options"
            MenuItem {
                text: "Reset"
                shortcut: "Ctrl+R"
                onTriggered: {
                    gameController.clickedBtnReset()
                }
            }
            MenuItem {
                text: "Undo"
                shortcut: "Ctrl+U"
                onTriggered: {
                    gameController.clickedBtnUndo()
                }
            }
        }

        Menu {
            title: "Server"
            MenuItem {
                text: "Your score"
                onTriggered: {
                }
            }
            MenuItem {
                text: "Find player online"
                onTriggered: {
                }
            }
        }

        Menu {
            title: "Languages"
            MenuItem {
                text: "English"
                onTriggered: {
                }
            }
            MenuItem {
                text: "Vietnamese"
                onTriggered: {
                }
            }
        }

        Menu {
            title: "About"
            MenuItem {
                text: "How to play"
                onTriggered: {
                }
            }
            MenuItem {
                text: "About apps"
                onTriggered: {
                }
            }
        }
    }

    GamePlayScreen {

    }

    Loader {
        id: loaderInputConnectionInfo
        active: false
        sourceComponent: DialogInputConnectionInfo {
            onInactivedLoader: {
                inactiveAllLoader()
            }
        }
    }

    Loader {
        id: loaderInputPlayerInfo
        active: false
        sourceComponent: DialogInputPlayerInfo {
            onInactivedLoader: {
                inactiveAllLoader()
            }
        }
    }

    Loader {
        id: loaderMenuReplay
        active: false
        sourceComponent: DialogMenuGameReplay {
            onInactivedLoader: {
                inactiveAllLoader()
            }
        }
    }

    function inactiveAllLoader(){
        loaderMenuReplay.active = false
        loaderInputPlayerInfo.active = false
        loaderInputConnectionInfo.active = false
    }
}
