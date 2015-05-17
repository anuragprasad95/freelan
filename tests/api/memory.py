"""
Types API tests.
"""

from .. import NativeTests

from pyfreelan.api import native, ffi


class APIMemoryTests(NativeTests):
    def test_malloc(self):
        result = native.freelan_malloc(6)

        self.assertNotEqual(ffi.NULL, result)

        native.freelan_free(result)

    def test_realloc(self):
        buf = native.freelan_malloc(6)
        result = native.freelan_realloc(buf, 12)

        self.assertNotEqual(ffi.NULL, result)

        native.freelan_free(result)

    def test_strdup(self):
        result = native.freelan_strdup("freelan")

        self.assertEqual("freelan", ffi.string(result))

        native.freelan_free(result)
