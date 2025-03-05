#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <Python.h>
#include <iostream>
#include "encryptWithPython.h"

static std::string encryptWithPython(const std::string& password) {

    // Initialize Python
    Py_Initialize();

    // Import the hashlib module
    PyObject* hashlib = PyImport_ImportModule("hashlib");
    if (!hashlib) {
        PyErr_Print();
        return "Error importing hashlib";
    }

    // Get the sha256 function
    PyObject* sha256_func = PyObject_GetAttrString(hashlib, "sha256");
    if (!sha256_func || !PyCallable_Check(sha256_func)) {
        PyErr_Print();
        return "Error finding sha256 function";
    }

    // Convert C++ string to Python string
    PyObject* pyPassword = PyUnicode_FromString(password.c_str());

    // Call hashlib.sha256(password.encode())
    PyObject* encodedPassword = PyObject_CallFunctionObjArgs(sha256_func, pyPassword, NULL);
    
    // Get the hexadecimal digest method
    PyObject* hexdigest_method = PyObject_GetAttrString(encodedPassword, "hexdigest");
    PyObject* hash_result = PyObject_CallFunctionObjArgs(hexdigest_method, NULL);

    // Convert Python string back to C++
    std::string hashedPassword = PyUnicode_AsUTF8(hash_result);

    // Clean up Python objects
    Py_DECREF(hashlib);
    Py_DECREF(sha256_func);
    Py_DECREF(pyPassword);
    Py_DECREF(encodedPassword);
    Py_DECREF(hexdigest_method);
    Py_DECREF(hash_result);

    // Finalize Python
    Py_Finalize();

    return hashedPassword;
}