#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11 沙振宇
#
#-------------------------------------------------
#by ZhenYu.Sha
TEMPLATE = subdirs

SUBDIRS += \
    src/application \
    src/quazip

application.depends = quazip
