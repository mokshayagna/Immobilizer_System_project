# ================= simple client-server =================
simple:
	gcc 02_simple_server.c -o s
	gcc 01_simple_client.c -o c

# ================= server with sleep =================
sleep:
	gcc 02_simple_server.c -o s
	gcc 03_server_sleep.c -o s

# ================= blocking client =================
blocking:
	gcc 02_simple_server.c -o s
	gcc 04_client_blocking.c -o c

# ================= non-blocking client =================
nonblocking:
	gcc 02_simple_server.c -o s
	gcc 05_client_nonblocking.c -o c

# ================= non-blocking client (alt) =================
nonblocking_alt:
	gcc 02_simple_server.c -o s
	gcc 06_client_nonblocking.c -o c

# ================= non-blocking client (2 sec) =================
nonblocking_2sec:
	gcc 02_simple_server.c -o s
	gcc 07_client_nonblocking2sec.c -o c

# ================= clean =================
clean:
	rm -f s c
