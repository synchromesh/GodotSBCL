/* GodotSBCL.h - Steel Bank Common Lisp as a Godot Engine extension.
 * File Created: 6 January 2025
 * Author: John Pallister <john@synchromesh.com>
 * Ref: https://github.com/asmaloney/GDExtensionTemplate
 * Ref: https://docs.godotengine.org/en/latest/tutorials/scripting/gdextension/gdextension_cpp_example.html#creating-a-simple-plugin
 *
 */

#pragma once
#ifndef GODOTSBCL_H
#define GODOTSBCL_H

#include <godot_cpp/classes/object.hpp>

//namespace godot { class ClassDB; }

class GodotSBCL : public godot::Object {
	GDCLASS( GodotSBCL, godot::Object )

protected:
	static void _bind_methods();

public:
	static godot::String version();
	static godot::String godotCppVersion();

	//GodotSBCL();
	//~GodotSBCL();
};

#endif

/*** End of GodotSBCL.h ***/
