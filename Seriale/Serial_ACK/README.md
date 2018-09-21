# Software / Hardware Serial example

This example send an array of bytes over the Software Serial, additing startMarker (<) and endMarker (>), to another arduino that listen over the Software Serial ( RX=10, TX=11 ) and print it without the markes on the Hardware Serial.

The sender wait the ACK from the Receiver to validate the transition.
If the Receiver do not send the ACK, the Sender re send the data.
