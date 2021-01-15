apps += Doom::App
app_headers += apps/doom/app.h

include apps/doom/engine/Makefile

apps_src += $(addprefix apps/doom/,\
  app.cpp \
  doom_controller.cpp \
  doom_view.cpp \
)


app_images += apps/doom/doom_icon.png

i18n_files += $(addprefix apps/doom/,\
	base.universal.i18n\
)

$(eval $(call depends_on_image,apps/doom/app.cpp,apps/doom/doom_icon.png))
