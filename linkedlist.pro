TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG -= UNIT_TESTS

UNIT_TESTS {
    SOURCES += \
        tests/linkedlist_test.c \
        tests/main_test.c
    DEFINES+= UNIT_TESTS
}
!UNIT_TESTS {
    SOURCES += \
        main.c
}

SOURCES += \
        linkedlist.c


HEADERS += \
    linkedlist.h




