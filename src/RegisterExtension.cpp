/* RegisterExtension.cpp
 * File Created: 12 February 2025
 * Author: John Pallister <john@synchromesh.com>
 * Ref: https://github.com/asmaloney/GDExtensionTemplate
 * Ref:
 * https://docs.godotengine.org/en/latest/tutorials/scripting/gdextension/gdextension_cpp_example.html#creating-a-simple-plugin
 *
 */

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "GodotSBCL.h"

/// @file
/// Register our GodotSBCL class(es) with Godot.

namespace {
using namespace godot;

/// @brief Called by Godot to let us register our classes with Godot.
///
/// @param level the level being initialized by Godot
///
/// @see GDExtensionInit
void initializeExtension(ModuleInitializationLevel level) {
  if (level == MODULE_INITIALIZATION_LEVEL_SCENE) {
    ClassDB::register_class<GodotSBCL>();
  }
}

/// @brief Called by Godot to let us do any cleanup.
///
/// @see GDExtensionInit
void uninitializeExtension(ModuleInitializationLevel level) {
  if (level == MODULE_INITIALIZATION_LEVEL_SCENE) {
    // pass
  }
}
}  // namespace

extern "C" {
/// @brief This is the entry point for the shared library.
///
/// @note The name of this function must match the "entry_symbol" in
/// templates/template.*.gdextension.in
///
/// @param get_proc_address the interface (need more info)
/// @param library the library (need more info)
/// @param initialization the intialization (need more info)
///
/// @returns GDExtensionBool
GDExtensionBool GDE_EXPORT
GDExtensionInit(GDExtensionInterfaceGetProcAddress get_proc_address,
                GDExtensionClassLibraryPtr library,
                GDExtensionInitialization *initialization) {
  GDExtensionBinding::InitObject init_obj(get_proc_address, library,
                                          initialization);

  init_obj.register_initializer(initializeExtension);
  init_obj.register_terminator(uninitializeExtension);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}
}

/*** End of RegisterExtension.cpp ***/
