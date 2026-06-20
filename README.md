# queue-management-system
About:
This project simulates a real-world service queue — like a bank or government office — where clients take numbered tickets and are served in order.

Features:
<li>Issue tickets with unique IDs (e.g. A1, A2).</li>
<li>Serve clients in FIFO order.</li>
<li>Track waiting and served clients.</li>
<li>Calculate expected wait time per ticket.</li>
<li>Print queue left-to-right and right-to-left.</li>
<li>Display a full line summary panel.</li>

How It Works:
<li>Client arrives → IssueTicket() → gets ticket (ID + wait time estimate)</li>
<li>Teller ready  → ServeNextClient() → removes front client from queue</li>
