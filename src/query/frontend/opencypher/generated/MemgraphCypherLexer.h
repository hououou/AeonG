
// Generated from /home/hjm/memgraph/src/query/frontend/opencypher/grammar/MemgraphCypherLexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"


namespace antlropencypher {


class  MemgraphCypherLexer : public antlr4::Lexer {
public:
  enum {
    UNDERSCORE = 1, AFTER = 2, ALTER = 3, ASYNC = 4, AUTH = 5, BAD = 6, 
    BATCH_INTERVAL = 7, BATCH_LIMIT = 8, BATCH_SIZE = 9, BEFORE = 10, BOOTSTRAP_SERVERS = 11, 
    CHECK = 12, CLEAR = 13, COMMIT = 14, COMMITTED = 15, CONFIG = 16, CONFIGS = 17, 
    CONSUMER_GROUP = 18, CREDENTIALS = 19, CSV = 20, DATA = 21, DELIMITER = 22, 
    DATABASE = 23, DENY = 24, DIRECTORY = 25, DROP = 26, DUMP = 27, DURABILITY = 28, 
    EXECUTE = 29, FOR = 30, FREE = 31, FREE_MEMORY = 32, FROM = 33, GLOBAL = 34, 
    GRANT = 35, GRANTS = 36, HEADER = 37, IDENTIFIED = 38, IGNORE = 39, 
    ISOLATION = 40, KAFKA = 41, LEVEL = 42, LOAD = 43, LOCK = 44, MAIN = 45, 
    MODE = 46, MODULE_READ = 47, MODULE_WRITE = 48, NEXT = 49, NO = 50, 
    PASSWORD = 51, PORT = 52, PRIVILEGES = 53, PULSAR = 54, READ = 55, READ_FILE = 56, 
    REGISTER = 57, REPLICA = 58, REPLICAS = 59, REPLICATION = 60, REVOKE = 61, 
    ROLE = 62, ROLES = 63, QUOTE = 64, SERVICE_URL = 65, SESSION = 66, SETTING = 67, 
    SETTINGS = 68, SNAPSHOT = 69, START = 70, STATS = 71, STOP = 72, STREAM = 73, 
    STREAMS = 74, SYNC = 75, TIMEOUT = 76, TO = 77, TOPICS = 78, TRANSACTION = 79, 
    TRANSFORM = 80, TRIGGER = 81, TRIGGERS = 82, UNCOMMITTED = 83, UNLOCK = 84, 
    UPDATE = 85, USER = 86, USERS = 87, VERSION = 88, WEBSOCKET = 89, Skipped = 90, 
    LPAREN = 91, RPAREN = 92, LBRACK = 93, RBRACK = 94, LBRACE = 95, RBRACE = 96, 
    COMMA = 97, DOT = 98, DOTS = 99, COLON = 100, SEMICOLON = 101, DOLLAR = 102, 
    PIPE = 103, EQ = 104, LT = 105, GT = 106, LTE = 107, GTE = 108, NEQ1 = 109, 
    NEQ2 = 110, SIM = 111, PLUS = 112, MINUS = 113, ASTERISK = 114, SLASH = 115, 
    PERCENT = 116, CARET = 117, PLUS_EQ = 118, LeftArrowHeadPart = 119, 
    RightArrowHeadPart = 120, DashPart = 121, ALL = 122, AND = 123, ANY = 124, 
    AS = 125, ASC = 126, ASCENDING = 127, ASSERT = 128, BFS = 129, BY = 130, 
    CALL = 131, CASE = 132, COALESCE = 133, CONSTRAINT = 134, CONTAINS = 135, 
    COUNT = 136, CREATE = 137, CYPHERNULL = 138, DELETE = 139, DESC = 140, 
    DESCENDING = 141, DETACH = 142, DISTINCT = 143, ELSE = 144, END = 145, 
    ENDS = 146, EXISTS = 147, EXPLAIN = 148, EXTRACT = 149, FALSE = 150, 
    FILTER = 151, IN = 152, INDEX = 153, INFO = 154, IS = 155, KB = 156, 
    KEY = 157, LIMIT = 158, L_SKIP = 159, MATCH = 160, MB = 161, MEMORY = 162, 
    MERGE = 163, NODE = 164, NONE = 165, NOT = 166, ON = 167, OPTIONAL = 168, 
    OR = 169, ORDER = 170, PROCEDURE = 171, PROFILE = 172, QUERY = 173, 
    REDUCE = 174, REMOVE = 175, RETURN = 176, SET = 177, SHOW = 178, SINGLE = 179, 
    STARTS = 180, STORAGE = 181, THEN = 182, TRUE = 183, TT = 184, UNION = 185, 
    UNIQUE = 186, UNLIMITED = 187, UNWIND = 188, WHEN = 189, WHERE = 190, 
    WITH = 191, WSHORTEST = 192, XOR = 193, YIELD = 194, StringLiteral = 195, 
    DecimalLiteral = 196, OctalLiteral = 197, HexadecimalLiteral = 198, 
    FloatingLiteral = 199, UnescapedSymbolicName = 200, EscapedSymbolicName = 201, 
    IdentifierStart = 202, IdentifierPart = 203
  };

  explicit MemgraphCypherLexer(antlr4::CharStream *input);
  ~MemgraphCypherLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlropencypher
