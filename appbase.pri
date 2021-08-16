lessThan(QT_MAJOR_VERSION, 6) {
  CONFIG += c++14
  windows:QMAKE_CXXFLAGS += /std:c++14
} else {
  CONFIG += c++17
  QT += core5compat
  windows:QMAKE_CXXFLAGS += /Zc:__cplusplus /std:c++17
}

windows {
  INCLUDEPATH += $$quote($$(TFDIR)\\include)
  LIBS += -L$$quote($$(TFDIR)\\bin)
  CONFIG(debug, debug|release) {
    LIBS += -ltreefrogd2
  } else {
    LIBS += -ltreefrog2
  }
} else {
  unix:LIBS += -Wl,-rpath,. -Wl,-rpath,/usr/local/Cellar/treefrog/2.0.2/lib -L/usr/local/Cellar/treefrog/2.0.2/lib -ltreefrog
  unix:INCLUDEPATH += /usr/local/Cellar/treefrog/2.0.2/include/treefrog
  linux-*:LIBS += -lrt
}
