#include <iostream>

extern "C" void oi_cpp() {
	std::cout << "C++: ola, fui chamado pelo Python!" << std::endl;
}

#ifndef BUILD_SHARED
#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main() {
	Py_Initialize();
	PyRun_SimpleString(
		"import sys; sys.path.insert(0, '.'); "
		"sys.stdout.reconfigure(line_buffering=True)");

	PyObject* m = PyImport_ImportModule("main");
	if (!m)
		PyErr_Print();
	else {
		PyObject* f = PyObject_GetAttrString(m, "oi_py");
		if (f) {
			PyObject_CallObject(f, nullptr);
			Py_DECREF(f);
		}
		Py_DECREF(m);
	}

	return 0;
}
#endif
