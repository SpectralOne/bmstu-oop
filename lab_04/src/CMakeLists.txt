file(GLOB LOCAL_SOURCE
	"cabin/*.*"
	"control_panel/*.*"
        "doors/*.*"
        "lift/*.*"
        "gui/*.*"
        "*.cpp"
)

set(LAB_SRC
	${LAB_SRC}
	${LOCAL_SOURCE}
	PARENT_SCOPE
	)