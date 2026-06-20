# queue-management-system
About:
This project simulates a real-world service queue — like a bank or government office — where clients take numbered tickets and are served in order.

Features:
-Issue tickets with unique IDs (e.g. A1, A2)
-Serve clients in FIFO order
-Track waiting and served clients
-Calculate expected wait time per ticket
-Print queue left-to-right and right-to-left
-Display a full line summary panel

How It Works:
Client arrives → IssueTicket() → gets ticket (ID + wait time estimate)
Teller ready  → ServeNextClient() → removes front client from queue
