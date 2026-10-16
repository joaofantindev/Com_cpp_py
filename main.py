print("Python: ola, fui chamado pelo C++!", flush=True)

def oi_py():
	print("Python: funcao oi_py rodando")

if __name__ == "__main__":
	import ctypes
	import os
	basedir = os.path.dirname(os.path.abspath(__file__))
	lib = ctypes.CDLL(os.path.join(basedir, "libok.so"))
	lib.oi_cpp()
