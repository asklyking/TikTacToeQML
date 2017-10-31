QT += qml quick network testlib

CONFIG += c++11

SOURCES += main.cpp \
    GameController.cpp \
    GameModel.cpp \
    GameGridViewModel.cpp \
    Move.cpp \
    Player.cpp \
    NetworkConnection.cpp \
    ClientConnection.cpp \
    ServerConnection.cpp \
    ListViewReplayModel.cpp \
    LanguageController.cpp \
    MinimaxAlgorithm.cpp \
    HttpRequestController.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    game_replay_data.json

HEADERS += \
    GameController.h \
    GameModel.h \
    GameGridViewModel.h \
    Constants.h \
    Utils.h \
    Move.h \
    Player.h \
    NetworkConnection.h \
    ClientConnection.h \
    ServerConnection.h \
    rapidjson/error/en.h \
    rapidjson/error/error.h \
    rapidjson/internal/biginteger.h \
    rapidjson/internal/diyfp.h \
    rapidjson/internal/dtoa.h \
    rapidjson/internal/ieee754.h \
    rapidjson/internal/itoa.h \
    rapidjson/internal/meta.h \
    rapidjson/internal/pow10.h \
    rapidjson/internal/regex.h \
    rapidjson/internal/stack.h \
    rapidjson/internal/strfunc.h \
    rapidjson/internal/strtod.h \
    rapidjson/internal/swap.h \
    rapidjson/msinttypes/inttypes.h \
    rapidjson/msinttypes/stdint.h \
    rapidjson/allocators.h \
    rapidjson/document.h \
    rapidjson/encodedstream.h \
    rapidjson/encodings.h \
    rapidjson/filereadstream.h \
    rapidjson/filewritestream.h \
    rapidjson/fwd.h \
    rapidjson/istreamwrapper.h \
    rapidjson/memorybuffer.h \
    rapidjson/memorystream.h \
    rapidjson/ostreamwrapper.h \
    rapidjson/pointer.h \
    rapidjson/prettywriter.h \
    rapidjson/rapidjson.h \
    rapidjson/reader.h \
    rapidjson/schema.h \
    rapidjson/stream.h \
    rapidjson/stringbuffer.h \
    rapidjson/writer.h \
    ListViewReplayModel.h \
    LanguageController.h \
    MinimaxAlgorithm.h \
    HttpRequestController.h


copydata.commands = $(COPY_DIR) $$PWD/game_replay_data.json $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
