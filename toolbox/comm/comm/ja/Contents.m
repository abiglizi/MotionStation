% Communications Toolbox
% Version 3.0 (R14) 05-May-2004
%
% ?îñ¹
%   randerr      - rbgëèp^?[Ì?ì?¬
%   randint      - êlªz·é???®?Ì?sñÌ?ì?¬
%   randsrc      - OàÁÄ?Ýèµ½At@xbgðgÁÄ?A_?sñ
%                  Ì?ì?¬
%   wgn          - ?FKEXmCYÌ?ì?¬
%
% ?M?ð?ÍÖ?
%   biterr       - rbgG?[?ÆrbgG?[?[gÌvZ
%   eyediagram   - ACp^?[Ì?¶?¬
%   scatterplot  - XL^?[v?bgÌ?¶?¬
%   symerr       - V{G?[?ÆV{G?[?[gÌvZ
%
% ?îñÌ?»
%   compand      - Ê@¥?AÜ½Í?AA@¥³?k/?L£Éæé?îñ¹?»
%   dpcmdeco     - ?·ªpX?Ï²û®ðgpµÄ?
%   dpcmenco     - ?·ªpX?Ï²û®ðgpµÄ?»
%   dpcmopt      - DPCMp??[^ð?ÅK»
%   lloyds       - LloydASYðgÁÄÊq»p??[^ð?ÅK»
%   quantiz      - Êq»CfbNXÆÊq»µ½?oÍlð?¶?¬
%
% ëè?§ä?»
%   bchpoly      - oCiBCH?Ìp??[^Ü½Í?¶?¬½?®ð?¶?¬
%   convenc      - ?ôÝ?Ý?»
%   cyclgen      - ?ñ?ÌpeB`FbN?sñ?A?¶?¬?sñð?¶?¬
%   cyclpoly     - ?ñ?Ì?¶?¬½?®ð?¶?¬
%   decode       - u?bN?
%   encode       - u?bN?»
%   gen2par      - ?¶?¬?sñðpeB`FbN?sñÖÏ·
%   gfweight     - ?ü`u?bN?Ì?Å?¬£ðvZ
%   hammgen      - Hamming?Ì?¶?¬?sñÆpeB`FbN?sñð?ì?¬
%   rsdec        - ?[h\??
%   rsenc        - ?[h\??»
%   rsdecof      - ?[h\??»³ê½ASCIIt@Cð?
%   rsencof      - ?[h\??»ðgÁÄASCIIt@Cð?»
%   rsgenpoly    - ?[h\??Ì?¶?¬½?®ð?ì?¬
%   syndtable    - Vh??[?e?[uð?¶?¬
%   vitdec       - ?ôÝ?Ý?»³ê½oCif?[^ðViterbiASYðgÁÄ?
%
% ëè?§ä?»pÌá??Ö?
%   bchdeco      - BCH ?
%   bchenco      - BCH ?»
%
% Ï²/²
%   ademod       - Ai?OpXoh²
%   ademodce     - Ai?Ox?[Xoh²
%   amod         - Ai?OpXohÏ²
%   amodce       - Ai?Ox?[XohÏ²
%   apkconst     - ~`ASK/PSK ?M?_zu?}Ìv?bg
%   ddemod       - fBW^pXoh²
%   ddemodce     - fBW^x?[Xoh²
%   demodmap     - ²?M?©çfBW^?bZ?[WÖf}bsO
%   dmod         - fBW^pXohÏ²
%   dmodce       - fBW^x?[XohÏ²
%   modmap       - fBW^?M?ðAi?O?M?Ö}bsO
%   qaskdeco     - QASK?³û?M?_zu©ç?bZ?[Wðf}bsO
%   qaskenco     - ?bZ?[WðQASK?³û?M?_zuÉ}bsO
%
% ÁêtB^
%   hank2sys     - nP?sñð?ü`VXeÉÏ·
%   hilbiir      - qxgÏ· IIR tB^
%   rcosflt      - RTC??[IttB^ðgÁÄ?AüÍ?M?ðtB
%                  ^O
%   rcosine      - RTC??[IttB^ð?Ýv
%
% ÁêtB^pÌá??Ö?
%   rcosfir      - RTC??[ItFIR tB^ð?Ýv
%   rcosiir      - RTC??[ItIIR tB^ð?Ýv
%
% `lÖ?
%   awgn         - ?FKEXmCYð?M?ÉtÁ 
%   
% K?AÌÌvZ
%   gfadd        - K?AÌ?ãÌ½?®Ìa
%   gfconv       - K?AÌ?ãÌ½?®Ì?Ï
%   gfcosets     - K?AÌÌ~üª?è]ÞÌ?ì?¬
%   gfdeconv     - K?AÌ?ãÌ½?®Ì?Z
%   gfdiv        - K?AÌÌ³Ì?Z
%   gffilter     - fK?AÌ?ãÌ½?®ðgÁ½f?[^ÌtB^O
%   gflineq      - fK?AÌ?ãÅ?ü`ûö®Ax = bðð­
%   gfminpol     - K?AÌÌ³Ì?Å?¬½?®ð?o
%   gfmul        - K?AÌÌ³Ì?æZ
%   gfplus       - 2ÂÌK?AÌÌ³ðÁZ
%   gfpretty     - ½?®ð?®`µÄ\¦
%   gfprimck     - K?AÌ?ãÌ½?®ª´n½?®Å é©`FbN
%   gfprimdf     - K?AÌÌftHg´n½?®ð?¶?¬
%   gfprimfd     - K?AÌÌ´n½?®ð?õ
%   gfrank       - K?AÌ?ãÌ?sñÌNðvZ
%   gfrepcov     - GF(2)?ãÌ½?®\»ð¼Ì\»ÉÏ·
%   gfroots      - fK?AÌ?ãÌ½?®Ì?ªÌ?o
%   gfsub        - K?AÌ?ãÌ½?®Ì¸Z
%   gftrunc      - K?AÌ?ãÌ½?®\»ðRpNgÉ\»
%   gftuple      - K?AÌÌ³ÌtH?[}bgðÈP»Ü½ÍÏ·
%
% ?[eBeB
%   bi2de        - 2?ixNgð10?i?ÉÏ·
%   de2bi        - 10?i?ð2?i?ÉÏ·
%   erf          - ë?·Ö?
%   erfc         - âë?·Ö?
%   istrellis    - üÍªÃÈgX?\¢Ì©Ç¤©`FbN
%   oct2dec      - 8?i?ð10?i?ÉÏ·
%   poly2trellis - ?ô?Ý?½?®ðgX\»ÉÏ·
%   vec2mat      - xNgð?sñÉÏ·
% 
% Q?l?F COMMDEMOS, SIGNAL.



% Generated from Contents.m_template revision 1.1.6.1
% Copyright 1996-2004 The MathWorks, Inc.
