/****************************************************************************
** Meta object code from reading C++ file 'GameController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameController_t {
    QByteArrayData data[26];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameController_t qt_meta_stringdata_GameController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GameController"
QT_MOC_LITERAL(1, 15, 20), // "isPlayer1TurnChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "isCurrentGameStateChanged"
QT_MOC_LITERAL(4, 63, 24), // "isCurrentGameModeChanged"
QT_MOC_LITERAL(5, 88, 24), // "makeMoveIfMessageChanged"
QT_MOC_LITERAL(6, 113, 15), // "clickedGameCell"
QT_MOC_LITERAL(7, 129, 5), // "index"
QT_MOC_LITERAL(8, 135, 15), // "clickedBtnReset"
QT_MOC_LITERAL(9, 151, 14), // "clickedBtnUndo"
QT_MOC_LITERAL(10, 166, 15), // "moveItemInModel"
QT_MOC_LITERAL(11, 182, 6), // "fromID"
QT_MOC_LITERAL(12, 189, 4), // "toID"
QT_MOC_LITERAL(13, 194, 18), // "replaySelectedGame"
QT_MOC_LITERAL(14, 213, 9), // "gameIndex"
QT_MOC_LITERAL(15, 223, 18), // "selectGameToReplay"
QT_MOC_LITERAL(16, 242, 16), // "startOfflineGame"
QT_MOC_LITERAL(17, 259, 14), // "strPlayer1Name"
QT_MOC_LITERAL(18, 274, 14), // "strPlayer2Name"
QT_MOC_LITERAL(19, 289, 14), // "startVsComGame"
QT_MOC_LITERAL(20, 304, 15), // "startOnlineGame"
QT_MOC_LITERAL(21, 320, 9), // "ipAddress"
QT_MOC_LITERAL(22, 330, 4), // "port"
QT_MOC_LITERAL(23, 335, 13), // "isPlayer1Turn"
QT_MOC_LITERAL(24, 349, 16), // "currentGameState"
QT_MOC_LITERAL(25, 366, 15) // "currentGameMode"

    },
    "GameController\0isPlayer1TurnChanged\0"
    "\0isCurrentGameStateChanged\0"
    "isCurrentGameModeChanged\0"
    "makeMoveIfMessageChanged\0clickedGameCell\0"
    "index\0clickedBtnReset\0clickedBtnUndo\0"
    "moveItemInModel\0fromID\0toID\0"
    "replaySelectedGame\0gameIndex\0"
    "selectGameToReplay\0startOfflineGame\0"
    "strPlayer1Name\0strPlayer2Name\0"
    "startVsComGame\0startOnlineGame\0ipAddress\0"
    "port\0isPlayer1Turn\0currentGameState\0"
    "currentGameMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   83,    2, 0x02 /* Public */,
       8,    0,   86,    2, 0x02 /* Public */,
       9,    0,   87,    2, 0x02 /* Public */,
      10,    2,   88,    2, 0x02 /* Public */,
      13,    1,   93,    2, 0x02 /* Public */,
      15,    0,   96,    2, 0x02 /* Public */,
      16,    2,   97,    2, 0x02 /* Public */,
      19,    0,  102,    2, 0x02 /* Public */,
      20,    2,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,

 // properties: name, type, flags
      23, QMetaType::Bool, 0x00495103,
      24, QMetaType::Int, 0x00495103,
      25, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void GameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameController *_t = static_cast<GameController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isPlayer1TurnChanged(); break;
        case 1: _t->isCurrentGameStateChanged(); break;
        case 2: _t->isCurrentGameModeChanged(); break;
        case 3: _t->makeMoveIfMessageChanged(); break;
        case 4: _t->clickedGameCell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->clickedBtnReset(); break;
        case 6: _t->clickedBtnUndo(); break;
        case 7: _t->moveItemInModel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->replaySelectedGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->selectGameToReplay(); break;
        case 10: _t->startOfflineGame((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->startVsComGame(); break;
        case 12: _t->startOnlineGame((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::isPlayer1TurnChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::isCurrentGameStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::isCurrentGameModeChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GameController *_t = static_cast<GameController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isPlayer1Turn(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentGameState(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->currentGameMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        GameController *_t = static_cast<GameController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsPlayer1Turn(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setCurrentGameState(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setCurrentGameMode(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject GameController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameController.data,
      qt_meta_data_GameController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameController.stringdata0))
        return static_cast<void*>(const_cast< GameController*>(this));
    return QObject::qt_metacast(_clname);
}

int GameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GameController::isPlayer1TurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GameController::isCurrentGameStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GameController::isCurrentGameModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
