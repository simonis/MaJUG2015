src/share/vm/utilities/debug.cpp

extern "C" void mixed_ps(intptr_t *sp, intptr_t *fp, unsigned char *pc) {
  // don't allocate large buffer on stack
  static char buf[O_BUFLEN];

  frame fr = (pc == NULL) ? os::current_frame() : frame(sp, fp, pc);

  // see if it's a valid frame
  if (fr.pc()) {
    tty->print_cr("Native frames: (J=compiled Java code, j=interpreted, Vv=VM code, C=native code)");

    int count = 0;

    while (count++ < StackPrintLimit) {
      fr.print_on_error(tty, buf, sizeof (buf));
      tty->cr();
      if (os::is_first_C_frame(&fr)) break;
      fr = os::get_sender_for_C_frame(&fr);
    }

    if (count > StackPrintLimit) {
      tty->print_cr("...<more frames>...");
    }

    tty->cr();
  }
}
