@tool
extends Terminal


func _ready():
	# Print every background color.
	for i in range(8):
		write("\u001b[4%dm " % i)  # Regular.
	for i in range(8):
		write("\u001b[10%dm " % i)  # Bright.
	write("\u001b[0m")  # Reset.

	# Print every foreground color.
	for i in range(8):
		write("\u001b[3%dm█" % i)  # Regular.
	for i in range(8):
		write("\u001b[9%dm█" % i)  # Bright.
	write("\u001b[0m")  # Reset.

	# Print every font.
	write("L\u001b[0m")  # Regular.
	write("\u001b[1mL\u001b[0m")  # Bold.
	write("\u001b[3mL\u001b[0m")  # Italic.
	write("\u001b[1m\u001b[3mL\u001b[0m")  # Bold Italic.
