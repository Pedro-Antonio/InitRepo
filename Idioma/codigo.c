#include <stdio.h>
#include <libintl.h>
#include <locale.h>

#define _(cadena) gettext(cadena)

int main(int argc, char const *argv[]) {
  /* code */
  bind_textdomain_codeset ("codigo", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("codigo", "idioma");
  textdomain("codigo");
  //char cadena[] = "Hola mundo piñata!";
  //char cadena1[] = _("Hola mundo piñata");
  printf(_("Hello world Intel-BUAP\n"));
  printf(_("Goodbye Intel-BUAP\n"));

  return 0;
}
