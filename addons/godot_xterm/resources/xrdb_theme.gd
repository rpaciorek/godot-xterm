extends Theme


func get_class() -> String:
	return "XrdbTheme"


func is_class(name) -> bool:
	return name == get_class() or super.is_class(name)
