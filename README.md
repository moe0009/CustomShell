# CustomShell

CustomShell is a basic shell application written in C that mimics some functionalities of a Unix shell. This project allows users to navigate directories, list files, create directories, view paths, and log session history through custom commands.

## Features

- **Custom Commands**:
  - `help`: Displays a list of available commands and their descriptions.
  - `tree`: Creates a directory structure with `Dir0` and `Dir1` inside it.
  - `list`: Clears the terminal and lists directory content in a file `tree.txt` and displays it.
  - `path`: Shows the current directory path and logs it in `path.txt`.
  - `exit`: Displays session history, lists the directory content, and logs the session history in `session_history.txt` before exiting.

- **Session History**:
  - Keeps track of all commands entered during the session.
  - Logs the session history to `session_history.txt`.

- **File Operations**:
  - Creates, writes, and reads from files such as `tree.txt`, `path.txt`, and `session_history.txt`.

- **Custom Prompt**:
  - Displays the current directory as part of the shell prompt.

## Files in the Repository

- **main.c**: Contains the code for the custom shell.
- **Makefile** (optional): You can include a `Makefile` for easier compilation if needed.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/moe0009/CustomShell.git
   cd CustomShell
