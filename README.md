Parser for traffic. Contains abstract parser class to be derived and chained for complex parsing by layers.
Contains native pcap parser and SIMBA SPECTRA Moscow Exchange protocol parser (but does not handle messages, fragmented to mutliple datagrams).

To run parse_pcap:
g++ parse_pcap.cpp -std=c++20 -o parse_pcap
./parse_pcap traffic.pcap data.bin

To run parse_simba:
g++ parse_simba.cpp -std=c++20 -o parse_simba
./parse_simba data.bin res.log
