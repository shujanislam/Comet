# Comet - A Mini Version Control System

**Comet** is a minimal version control simulation tool built using C++. It allows you to initialize a repository, commit files to it, and simulate pushing those files to a remote directory — all via command line.

---

---

## ⚙️ Features

- `-i <repo_name>` → Initializes a new local repository
- `-c <repo_name> <file>` → Commits (copies) the specified file to the local repository
- `-p <repo_name>` → Pushes the committed files from local to the remote directory

---

## 🧱 How It Works

- Repositories are created in:  
  `/home/shujan/Programming/comet_repos/<repo_name>/`

- "Remote" repositories are simulated at:  
  `/home/shujan/Programming/comet_remote/<repo_name>/`

---

## 🔧 Usage

Compile the program:

```bash
g++ -std=c++17 src/main.cpp -o comet
