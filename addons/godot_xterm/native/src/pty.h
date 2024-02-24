// SPDX-FileCopyrightText: 2021-2024 Leroy Hopson <godot-xterm@leroy.nix.nz>
// SPDX-License-Identifier: MIT

#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/os.hpp>

namespace godot
{
  class PTY : public Node
  {
    GDCLASS(PTY, Node)

  public:
    enum Signal {
      SIGNAL_SIGHUP = 1,
      SIGNAL_SIGINT = 2,
      SIGNAL_SIGQUIT = 3,
      SIGNAL_SIGILL = 4,
      SIGNAL_SIGTRAP = 5,
      SIGNAL_SIGABRT = 6,
      SIGNAL_SIGBUS = 7,
      SIGNAL_SIGFPE = 8,
      SIGNAL_SIGKILL = 9,
      SIGNAL_SIGUSR1 = 10,
      SIGNAL_SIGSEGV = 11,
      SIGNAL_SIGUSR2 = 12,
      SIGNAL_SIGPIPE = 13,
      SIGNAL_SIGALRM = 14,
      SIGNAL_SIGTERM = 15,
    };

    PTY();
    ~PTY();

    int get_cols() const;
    int get_rows() const;

    Dictionary get_env() const;
    void set_env(const Dictionary &value);

    bool get_use_os_env() const;
    void set_use_os_env(const bool value);

    Error fork(const String &file = "", const PackedStringArray &args = PackedStringArray(), const String &cwd = ".", const int cols = 80, const int rows = 24);
    void kill(const int signum = Signal::SIGNAL_SIGHUP);
    Error open(const int cols = 80, const int rows = 24) const;
    void resize(const int cols, const int rows) const;
    void resizev(const Vector2i &size) const { resize(size.x, size.y); };
    void write(const Variant &data) const;

  protected:
    static void _bind_methods();

  private:
    OS *os;

    int pid = -1;
    int fd = -1;

    unsigned int cols = 0;
    unsigned int rows = 0;

    Dictionary env = Dictionary();
    bool use_os_env = true;

    String _get_fork_file(const String &file) const;
    Dictionary _get_fork_env() const;
    void _on_exit(int exit_code, int exit_signal);
  };
} // namespace godot

VARIANT_ENUM_CAST(PTY::Signal);