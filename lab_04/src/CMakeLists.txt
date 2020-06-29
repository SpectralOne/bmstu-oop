file(GLOB LOCAL_SOURCE
	"cabin/*.*"
	"control_panel/*.*"
        "doors/*.*"
        "lift/*.*"
        "gui/*.*"
        "*.cpp"
)

set(CLIENT_SOURCES
	${CLIENT_SOURCES}
	${LOCAL_SOURCE}
	PARENT_SCOPE
	)