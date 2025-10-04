# Return Qt translations files as list of paths
# It will return .qm files of qt/qtbase that aren't stub files.
# Requires that Qt has been found first because it depends on qmake being available

function(_get_qt_translations qt_translations)
    get_target_property(QT_QMAKE_EXECUTABLE Qt::qmake IMPORTED_LOCATION)
    execute_process(COMMAND "${QT_QMAKE_EXECUTABLE}" -query QT_INSTALL_TRANSLATIONS
                    OUTPUT_VARIABLE QT_TRANSLATIONS_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)

    file(GLOB QT_TEMP_TRANSLATIONS CONFIGURE_DEPENDS
        "${QT_TRANSLATIONS_DIR}/qt_??.qm"
        "${QT_TRANSLATIONS_DIR}/qt_??_??.qm"
        "${QT_TRANSLATIONS_DIR}/qtbase_??.qm"
        "${QT_TRANSLATIONS_DIR}/qtbase_??_??.qm")

    foreach(TRANSLATION ${QT_TEMP_TRANSLATIONS})
        file(SIZE "${TRANSLATION}" translation_size)

        if (translation_size GREATER_EQUAL 10240)
            list(APPEND QT_FINAL_TRANSLATIONS "${TRANSLATION}")
        endif()

    endforeach()

    set(${qt_translations} ${QT_FINAL_TRANSLATIONS} PARENT_SCOPE)

endfunction()
