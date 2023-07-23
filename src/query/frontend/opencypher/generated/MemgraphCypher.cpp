
// Generated from /home/hjm/memgraph/src/query/frontend/opencypher/grammar/MemgraphCypher.g4 by ANTLR 4.9.2


#include "MemgraphCypherListener.h"
#include "MemgraphCypherVisitor.h"

#include "MemgraphCypher.h"


using namespace antlrcpp;
using namespace antlropencypher;
using namespace antlr4;

MemgraphCypher::MemgraphCypher(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MemgraphCypher::~MemgraphCypher() {
  delete _interpreter;
}

std::string MemgraphCypher::getGrammarFileName() const {
  return "MemgraphCypher.g4";
}

const std::vector<std::string>& MemgraphCypher::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MemgraphCypher::getVocabulary() const {
  return _vocabulary;
}


//----------------- MemgraphCypherKeywordContext ------------------------------------------------------------------

MemgraphCypher::MemgraphCypherKeywordContext::MemgraphCypherKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CypherKeywordContext* MemgraphCypher::MemgraphCypherKeywordContext::cypherKeyword() {
  return getRuleContext<MemgraphCypher::CypherKeywordContext>(0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::AFTER() {
  return getToken(MemgraphCypher::AFTER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::ALTER() {
  return getToken(MemgraphCypher::ALTER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::ASYNC() {
  return getToken(MemgraphCypher::ASYNC, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::AUTH() {
  return getToken(MemgraphCypher::AUTH, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BAD() {
  return getToken(MemgraphCypher::BAD, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BATCH_INTERVAL() {
  return getToken(MemgraphCypher::BATCH_INTERVAL, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BATCH_LIMIT() {
  return getToken(MemgraphCypher::BATCH_LIMIT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BATCH_SIZE() {
  return getToken(MemgraphCypher::BATCH_SIZE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BEFORE() {
  return getToken(MemgraphCypher::BEFORE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::BOOTSTRAP_SERVERS() {
  return getToken(MemgraphCypher::BOOTSTRAP_SERVERS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CHECK() {
  return getToken(MemgraphCypher::CHECK, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CLEAR() {
  return getToken(MemgraphCypher::CLEAR, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::COMMIT() {
  return getToken(MemgraphCypher::COMMIT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::COMMITTED() {
  return getToken(MemgraphCypher::COMMITTED, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CONFIG() {
  return getToken(MemgraphCypher::CONFIG, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CONFIGS() {
  return getToken(MemgraphCypher::CONFIGS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CONSUMER_GROUP() {
  return getToken(MemgraphCypher::CONSUMER_GROUP, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CREDENTIALS() {
  return getToken(MemgraphCypher::CREDENTIALS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::CSV() {
  return getToken(MemgraphCypher::CSV, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DATA() {
  return getToken(MemgraphCypher::DATA, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DELIMITER() {
  return getToken(MemgraphCypher::DELIMITER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DATABASE() {
  return getToken(MemgraphCypher::DATABASE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DENY() {
  return getToken(MemgraphCypher::DENY, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::DUMP() {
  return getToken(MemgraphCypher::DUMP, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::EXECUTE() {
  return getToken(MemgraphCypher::EXECUTE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::FREE() {
  return getToken(MemgraphCypher::FREE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::FROM() {
  return getToken(MemgraphCypher::FROM, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::GLOBAL() {
  return getToken(MemgraphCypher::GLOBAL, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::GRANT() {
  return getToken(MemgraphCypher::GRANT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::HEADER() {
  return getToken(MemgraphCypher::HEADER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::IDENTIFIED() {
  return getToken(MemgraphCypher::IDENTIFIED, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::ISOLATION() {
  return getToken(MemgraphCypher::ISOLATION, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::KAFKA() {
  return getToken(MemgraphCypher::KAFKA, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::LEVEL() {
  return getToken(MemgraphCypher::LEVEL, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::LOAD() {
  return getToken(MemgraphCypher::LOAD, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::LOCK() {
  return getToken(MemgraphCypher::LOCK, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::MAIN() {
  return getToken(MemgraphCypher::MAIN, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::MODE() {
  return getToken(MemgraphCypher::MODE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::NEXT() {
  return getToken(MemgraphCypher::NEXT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::NO() {
  return getToken(MemgraphCypher::NO, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::PASSWORD() {
  return getToken(MemgraphCypher::PASSWORD, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::PULSAR() {
  return getToken(MemgraphCypher::PULSAR, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::PORT() {
  return getToken(MemgraphCypher::PORT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::PRIVILEGES() {
  return getToken(MemgraphCypher::PRIVILEGES, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::READ() {
  return getToken(MemgraphCypher::READ, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::REGISTER() {
  return getToken(MemgraphCypher::REGISTER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::REPLICA() {
  return getToken(MemgraphCypher::REPLICA, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::REPLICAS() {
  return getToken(MemgraphCypher::REPLICAS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::REPLICATION() {
  return getToken(MemgraphCypher::REPLICATION, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::REVOKE() {
  return getToken(MemgraphCypher::REVOKE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::ROLES() {
  return getToken(MemgraphCypher::ROLES, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::QUOTE() {
  return getToken(MemgraphCypher::QUOTE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::SESSION() {
  return getToken(MemgraphCypher::SESSION, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::SETTING() {
  return getToken(MemgraphCypher::SETTING, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::SETTINGS() {
  return getToken(MemgraphCypher::SETTINGS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::SNAPSHOT() {
  return getToken(MemgraphCypher::SNAPSHOT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::START() {
  return getToken(MemgraphCypher::START, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::STATS() {
  return getToken(MemgraphCypher::STATS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::STREAMS() {
  return getToken(MemgraphCypher::STREAMS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::SYNC() {
  return getToken(MemgraphCypher::SYNC, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TIMEOUT() {
  return getToken(MemgraphCypher::TIMEOUT, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TOPICS() {
  return getToken(MemgraphCypher::TOPICS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TRANSACTION() {
  return getToken(MemgraphCypher::TRANSACTION, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TRANSFORM() {
  return getToken(MemgraphCypher::TRANSFORM, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TRIGGER() {
  return getToken(MemgraphCypher::TRIGGER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::TRIGGERS() {
  return getToken(MemgraphCypher::TRIGGERS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::UNCOMMITTED() {
  return getToken(MemgraphCypher::UNCOMMITTED, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::UNLOCK() {
  return getToken(MemgraphCypher::UNLOCK, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::UPDATE() {
  return getToken(MemgraphCypher::UPDATE, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::USER() {
  return getToken(MemgraphCypher::USER, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::USERS() {
  return getToken(MemgraphCypher::USERS, 0);
}

tree::TerminalNode* MemgraphCypher::MemgraphCypherKeywordContext::VERSION() {
  return getToken(MemgraphCypher::VERSION, 0);
}


size_t MemgraphCypher::MemgraphCypherKeywordContext::getRuleIndex() const {
  return MemgraphCypher::RuleMemgraphCypherKeyword;
}

void MemgraphCypher::MemgraphCypherKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemgraphCypherKeyword(this);
}

void MemgraphCypher::MemgraphCypherKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemgraphCypherKeyword(this);
}


antlrcpp::Any MemgraphCypher::MemgraphCypherKeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitMemgraphCypherKeyword(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::MemgraphCypherKeywordContext* MemgraphCypher::memgraphCypherKeyword() {
  MemgraphCypherKeywordContext *_localctx = _tracker.createInstance<MemgraphCypherKeywordContext>(_ctx, getState());
  enterRule(_localctx, 0, MemgraphCypher::RuleMemgraphCypherKeyword);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(454);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(376);
      cypherKeyword();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(377);
      match(MemgraphCypher::AFTER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(378);
      match(MemgraphCypher::ALTER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(379);
      match(MemgraphCypher::ASYNC);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(380);
      match(MemgraphCypher::AUTH);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(381);
      match(MemgraphCypher::BAD);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(382);
      match(MemgraphCypher::BATCH_INTERVAL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(383);
      match(MemgraphCypher::BATCH_LIMIT);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(384);
      match(MemgraphCypher::BATCH_SIZE);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(385);
      match(MemgraphCypher::BEFORE);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(386);
      match(MemgraphCypher::BOOTSTRAP_SERVERS);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(387);
      match(MemgraphCypher::CHECK);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(388);
      match(MemgraphCypher::CLEAR);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(389);
      match(MemgraphCypher::COMMIT);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(390);
      match(MemgraphCypher::COMMITTED);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(391);
      match(MemgraphCypher::CONFIG);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(392);
      match(MemgraphCypher::CONFIGS);
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(393);
      match(MemgraphCypher::CONSUMER_GROUP);
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(394);
      match(MemgraphCypher::CREDENTIALS);
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(395);
      match(MemgraphCypher::CSV);
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(396);
      match(MemgraphCypher::DATA);
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(397);
      match(MemgraphCypher::DELIMITER);
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(398);
      match(MemgraphCypher::DATABASE);
      break;
    }

    case 24: {
      enterOuterAlt(_localctx, 24);
      setState(399);
      match(MemgraphCypher::DENY);
      break;
    }

    case 25: {
      enterOuterAlt(_localctx, 25);
      setState(400);
      match(MemgraphCypher::DROP);
      break;
    }

    case 26: {
      enterOuterAlt(_localctx, 26);
      setState(401);
      match(MemgraphCypher::DUMP);
      break;
    }

    case 27: {
      enterOuterAlt(_localctx, 27);
      setState(402);
      match(MemgraphCypher::EXECUTE);
      break;
    }

    case 28: {
      enterOuterAlt(_localctx, 28);
      setState(403);
      match(MemgraphCypher::FOR);
      break;
    }

    case 29: {
      enterOuterAlt(_localctx, 29);
      setState(404);
      match(MemgraphCypher::FREE);
      break;
    }

    case 30: {
      enterOuterAlt(_localctx, 30);
      setState(405);
      match(MemgraphCypher::FROM);
      break;
    }

    case 31: {
      enterOuterAlt(_localctx, 31);
      setState(406);
      match(MemgraphCypher::GLOBAL);
      break;
    }

    case 32: {
      enterOuterAlt(_localctx, 32);
      setState(407);
      match(MemgraphCypher::GRANT);
      break;
    }

    case 33: {
      enterOuterAlt(_localctx, 33);
      setState(408);
      match(MemgraphCypher::HEADER);
      break;
    }

    case 34: {
      enterOuterAlt(_localctx, 34);
      setState(409);
      match(MemgraphCypher::IDENTIFIED);
      break;
    }

    case 35: {
      enterOuterAlt(_localctx, 35);
      setState(410);
      match(MemgraphCypher::ISOLATION);
      break;
    }

    case 36: {
      enterOuterAlt(_localctx, 36);
      setState(411);
      match(MemgraphCypher::KAFKA);
      break;
    }

    case 37: {
      enterOuterAlt(_localctx, 37);
      setState(412);
      match(MemgraphCypher::LEVEL);
      break;
    }

    case 38: {
      enterOuterAlt(_localctx, 38);
      setState(413);
      match(MemgraphCypher::LOAD);
      break;
    }

    case 39: {
      enterOuterAlt(_localctx, 39);
      setState(414);
      match(MemgraphCypher::LOCK);
      break;
    }

    case 40: {
      enterOuterAlt(_localctx, 40);
      setState(415);
      match(MemgraphCypher::MAIN);
      break;
    }

    case 41: {
      enterOuterAlt(_localctx, 41);
      setState(416);
      match(MemgraphCypher::MODE);
      break;
    }

    case 42: {
      enterOuterAlt(_localctx, 42);
      setState(417);
      match(MemgraphCypher::NEXT);
      break;
    }

    case 43: {
      enterOuterAlt(_localctx, 43);
      setState(418);
      match(MemgraphCypher::NO);
      break;
    }

    case 44: {
      enterOuterAlt(_localctx, 44);
      setState(419);
      match(MemgraphCypher::PASSWORD);
      break;
    }

    case 45: {
      enterOuterAlt(_localctx, 45);
      setState(420);
      match(MemgraphCypher::PULSAR);
      break;
    }

    case 46: {
      enterOuterAlt(_localctx, 46);
      setState(421);
      match(MemgraphCypher::PORT);
      break;
    }

    case 47: {
      enterOuterAlt(_localctx, 47);
      setState(422);
      match(MemgraphCypher::PRIVILEGES);
      break;
    }

    case 48: {
      enterOuterAlt(_localctx, 48);
      setState(423);
      match(MemgraphCypher::READ);
      break;
    }

    case 49: {
      enterOuterAlt(_localctx, 49);
      setState(424);
      match(MemgraphCypher::REGISTER);
      break;
    }

    case 50: {
      enterOuterAlt(_localctx, 50);
      setState(425);
      match(MemgraphCypher::REPLICA);
      break;
    }

    case 51: {
      enterOuterAlt(_localctx, 51);
      setState(426);
      match(MemgraphCypher::REPLICAS);
      break;
    }

    case 52: {
      enterOuterAlt(_localctx, 52);
      setState(427);
      match(MemgraphCypher::REPLICATION);
      break;
    }

    case 53: {
      enterOuterAlt(_localctx, 53);
      setState(428);
      match(MemgraphCypher::REVOKE);
      break;
    }

    case 54: {
      enterOuterAlt(_localctx, 54);
      setState(429);
      match(MemgraphCypher::ROLE);
      break;
    }

    case 55: {
      enterOuterAlt(_localctx, 55);
      setState(430);
      match(MemgraphCypher::ROLES);
      break;
    }

    case 56: {
      enterOuterAlt(_localctx, 56);
      setState(431);
      match(MemgraphCypher::QUOTE);
      break;
    }

    case 57: {
      enterOuterAlt(_localctx, 57);
      setState(432);
      match(MemgraphCypher::SESSION);
      break;
    }

    case 58: {
      enterOuterAlt(_localctx, 58);
      setState(433);
      match(MemgraphCypher::SETTING);
      break;
    }

    case 59: {
      enterOuterAlt(_localctx, 59);
      setState(434);
      match(MemgraphCypher::SETTINGS);
      break;
    }

    case 60: {
      enterOuterAlt(_localctx, 60);
      setState(435);
      match(MemgraphCypher::SNAPSHOT);
      break;
    }

    case 61: {
      enterOuterAlt(_localctx, 61);
      setState(436);
      match(MemgraphCypher::START);
      break;
    }

    case 62: {
      enterOuterAlt(_localctx, 62);
      setState(437);
      match(MemgraphCypher::STATS);
      break;
    }

    case 63: {
      enterOuterAlt(_localctx, 63);
      setState(438);
      match(MemgraphCypher::STREAM);
      break;
    }

    case 64: {
      enterOuterAlt(_localctx, 64);
      setState(439);
      match(MemgraphCypher::STREAMS);
      break;
    }

    case 65: {
      enterOuterAlt(_localctx, 65);
      setState(440);
      match(MemgraphCypher::SYNC);
      break;
    }

    case 66: {
      enterOuterAlt(_localctx, 66);
      setState(441);
      match(MemgraphCypher::TIMEOUT);
      break;
    }

    case 67: {
      enterOuterAlt(_localctx, 67);
      setState(442);
      match(MemgraphCypher::TO);
      break;
    }

    case 68: {
      enterOuterAlt(_localctx, 68);
      setState(443);
      match(MemgraphCypher::TOPICS);
      break;
    }

    case 69: {
      enterOuterAlt(_localctx, 69);
      setState(444);
      match(MemgraphCypher::TRANSACTION);
      break;
    }

    case 70: {
      enterOuterAlt(_localctx, 70);
      setState(445);
      match(MemgraphCypher::TRANSFORM);
      break;
    }

    case 71: {
      enterOuterAlt(_localctx, 71);
      setState(446);
      match(MemgraphCypher::TRIGGER);
      break;
    }

    case 72: {
      enterOuterAlt(_localctx, 72);
      setState(447);
      match(MemgraphCypher::TRIGGERS);
      break;
    }

    case 73: {
      enterOuterAlt(_localctx, 73);
      setState(448);
      match(MemgraphCypher::UNCOMMITTED);
      break;
    }

    case 74: {
      enterOuterAlt(_localctx, 74);
      setState(449);
      match(MemgraphCypher::UNLOCK);
      break;
    }

    case 75: {
      enterOuterAlt(_localctx, 75);
      setState(450);
      match(MemgraphCypher::UPDATE);
      break;
    }

    case 76: {
      enterOuterAlt(_localctx, 76);
      setState(451);
      match(MemgraphCypher::USER);
      break;
    }

    case 77: {
      enterOuterAlt(_localctx, 77);
      setState(452);
      match(MemgraphCypher::USERS);
      break;
    }

    case 78: {
      enterOuterAlt(_localctx, 78);
      setState(453);
      match(MemgraphCypher::VERSION);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolicNameContext ------------------------------------------------------------------

MemgraphCypher::SymbolicNameContext::SymbolicNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SymbolicNameContext::UnescapedSymbolicName() {
  return getToken(MemgraphCypher::UnescapedSymbolicName, 0);
}

tree::TerminalNode* MemgraphCypher::SymbolicNameContext::EscapedSymbolicName() {
  return getToken(MemgraphCypher::EscapedSymbolicName, 0);
}

MemgraphCypher::MemgraphCypherKeywordContext* MemgraphCypher::SymbolicNameContext::memgraphCypherKeyword() {
  return getRuleContext<MemgraphCypher::MemgraphCypherKeywordContext>(0);
}


size_t MemgraphCypher::SymbolicNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleSymbolicName;
}

void MemgraphCypher::SymbolicNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbolicName(this);
}

void MemgraphCypher::SymbolicNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbolicName(this);
}


antlrcpp::Any MemgraphCypher::SymbolicNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSymbolicName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::symbolicName() {
  SymbolicNameContext *_localctx = _tracker.createInstance<SymbolicNameContext>(_ctx, getState());
  enterRule(_localctx, 2, MemgraphCypher::RuleSymbolicName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(459);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::UnescapedSymbolicName: {
        enterOuterAlt(_localctx, 1);
        setState(456);
        match(MemgraphCypher::UnescapedSymbolicName);
        break;
      }

      case MemgraphCypher::EscapedSymbolicName: {
        enterOuterAlt(_localctx, 2);
        setState(457);
        match(MemgraphCypher::EscapedSymbolicName);
        break;
      }

      case MemgraphCypher::AFTER:
      case MemgraphCypher::ALTER:
      case MemgraphCypher::ASYNC:
      case MemgraphCypher::AUTH:
      case MemgraphCypher::BAD:
      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_LIMIT:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::BEFORE:
      case MemgraphCypher::BOOTSTRAP_SERVERS:
      case MemgraphCypher::CHECK:
      case MemgraphCypher::CLEAR:
      case MemgraphCypher::COMMIT:
      case MemgraphCypher::COMMITTED:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::CONFIGS:
      case MemgraphCypher::CONSUMER_GROUP:
      case MemgraphCypher::CREDENTIALS:
      case MemgraphCypher::CSV:
      case MemgraphCypher::DATA:
      case MemgraphCypher::DELIMITER:
      case MemgraphCypher::DATABASE:
      case MemgraphCypher::DENY:
      case MemgraphCypher::DROP:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::EXECUTE:
      case MemgraphCypher::FOR:
      case MemgraphCypher::FREE:
      case MemgraphCypher::FROM:
      case MemgraphCypher::GLOBAL:
      case MemgraphCypher::GRANT:
      case MemgraphCypher::HEADER:
      case MemgraphCypher::IDENTIFIED:
      case MemgraphCypher::ISOLATION:
      case MemgraphCypher::KAFKA:
      case MemgraphCypher::LEVEL:
      case MemgraphCypher::LOAD:
      case MemgraphCypher::LOCK:
      case MemgraphCypher::MAIN:
      case MemgraphCypher::MODE:
      case MemgraphCypher::NEXT:
      case MemgraphCypher::NO:
      case MemgraphCypher::PASSWORD:
      case MemgraphCypher::PORT:
      case MemgraphCypher::PRIVILEGES:
      case MemgraphCypher::PULSAR:
      case MemgraphCypher::READ:
      case MemgraphCypher::REGISTER:
      case MemgraphCypher::REPLICA:
      case MemgraphCypher::REPLICAS:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::REVOKE:
      case MemgraphCypher::ROLE:
      case MemgraphCypher::ROLES:
      case MemgraphCypher::QUOTE:
      case MemgraphCypher::SESSION:
      case MemgraphCypher::SETTING:
      case MemgraphCypher::SETTINGS:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::START:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::STREAMS:
      case MemgraphCypher::SYNC:
      case MemgraphCypher::TIMEOUT:
      case MemgraphCypher::TO:
      case MemgraphCypher::TOPICS:
      case MemgraphCypher::TRANSACTION:
      case MemgraphCypher::TRANSFORM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::TRIGGERS:
      case MemgraphCypher::UNCOMMITTED:
      case MemgraphCypher::UNLOCK:
      case MemgraphCypher::UPDATE:
      case MemgraphCypher::USER:
      case MemgraphCypher::USERS:
      case MemgraphCypher::VERSION:
      case MemgraphCypher::ALL:
      case MemgraphCypher::AND:
      case MemgraphCypher::ANY:
      case MemgraphCypher::AS:
      case MemgraphCypher::ASC:
      case MemgraphCypher::ASCENDING:
      case MemgraphCypher::ASSERT:
      case MemgraphCypher::BFS:
      case MemgraphCypher::BY:
      case MemgraphCypher::CALL:
      case MemgraphCypher::CASE:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CONTAINS:
      case MemgraphCypher::COUNT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::CYPHERNULL:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::DESC:
      case MemgraphCypher::DESCENDING:
      case MemgraphCypher::DETACH:
      case MemgraphCypher::DISTINCT:
      case MemgraphCypher::ELSE:
      case MemgraphCypher::END:
      case MemgraphCypher::ENDS:
      case MemgraphCypher::EXISTS:
      case MemgraphCypher::EXPLAIN:
      case MemgraphCypher::EXTRACT:
      case MemgraphCypher::FALSE:
      case MemgraphCypher::FILTER:
      case MemgraphCypher::IN:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::INFO:
      case MemgraphCypher::IS:
      case MemgraphCypher::KEY:
      case MemgraphCypher::LIMIT:
      case MemgraphCypher::L_SKIP:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::NODE:
      case MemgraphCypher::NONE:
      case MemgraphCypher::NOT:
      case MemgraphCypher::ON:
      case MemgraphCypher::OPTIONAL:
      case MemgraphCypher::OR:
      case MemgraphCypher::ORDER:
      case MemgraphCypher::PROCEDURE:
      case MemgraphCypher::PROFILE:
      case MemgraphCypher::QUERY:
      case MemgraphCypher::REDUCE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::RETURN:
      case MemgraphCypher::SET:
      case MemgraphCypher::SHOW:
      case MemgraphCypher::SINGLE:
      case MemgraphCypher::STARTS:
      case MemgraphCypher::STORAGE:
      case MemgraphCypher::THEN:
      case MemgraphCypher::TRUE:
      case MemgraphCypher::TT:
      case MemgraphCypher::UNION:
      case MemgraphCypher::UNIQUE:
      case MemgraphCypher::UNWIND:
      case MemgraphCypher::WHEN:
      case MemgraphCypher::WHERE:
      case MemgraphCypher::WITH:
      case MemgraphCypher::WSHORTEST:
      case MemgraphCypher::XOR:
      case MemgraphCypher::YIELD: {
        enterOuterAlt(_localctx, 3);
        setState(458);
        memgraphCypherKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryContext ------------------------------------------------------------------

MemgraphCypher::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CypherQueryContext* MemgraphCypher::QueryContext::cypherQuery() {
  return getRuleContext<MemgraphCypher::CypherQueryContext>(0);
}

MemgraphCypher::IndexQueryContext* MemgraphCypher::QueryContext::indexQuery() {
  return getRuleContext<MemgraphCypher::IndexQueryContext>(0);
}

MemgraphCypher::ExplainQueryContext* MemgraphCypher::QueryContext::explainQuery() {
  return getRuleContext<MemgraphCypher::ExplainQueryContext>(0);
}

MemgraphCypher::ProfileQueryContext* MemgraphCypher::QueryContext::profileQuery() {
  return getRuleContext<MemgraphCypher::ProfileQueryContext>(0);
}

MemgraphCypher::InfoQueryContext* MemgraphCypher::QueryContext::infoQuery() {
  return getRuleContext<MemgraphCypher::InfoQueryContext>(0);
}

MemgraphCypher::ConstraintQueryContext* MemgraphCypher::QueryContext::constraintQuery() {
  return getRuleContext<MemgraphCypher::ConstraintQueryContext>(0);
}

MemgraphCypher::AuthQueryContext* MemgraphCypher::QueryContext::authQuery() {
  return getRuleContext<MemgraphCypher::AuthQueryContext>(0);
}

MemgraphCypher::DumpQueryContext* MemgraphCypher::QueryContext::dumpQuery() {
  return getRuleContext<MemgraphCypher::DumpQueryContext>(0);
}

MemgraphCypher::ReplicationQueryContext* MemgraphCypher::QueryContext::replicationQuery() {
  return getRuleContext<MemgraphCypher::ReplicationQueryContext>(0);
}

MemgraphCypher::LockPathQueryContext* MemgraphCypher::QueryContext::lockPathQuery() {
  return getRuleContext<MemgraphCypher::LockPathQueryContext>(0);
}

MemgraphCypher::FreeMemoryQueryContext* MemgraphCypher::QueryContext::freeMemoryQuery() {
  return getRuleContext<MemgraphCypher::FreeMemoryQueryContext>(0);
}

MemgraphCypher::TriggerQueryContext* MemgraphCypher::QueryContext::triggerQuery() {
  return getRuleContext<MemgraphCypher::TriggerQueryContext>(0);
}

MemgraphCypher::IsolationLevelQueryContext* MemgraphCypher::QueryContext::isolationLevelQuery() {
  return getRuleContext<MemgraphCypher::IsolationLevelQueryContext>(0);
}

MemgraphCypher::CreateSnapshotQueryContext* MemgraphCypher::QueryContext::createSnapshotQuery() {
  return getRuleContext<MemgraphCypher::CreateSnapshotQueryContext>(0);
}

MemgraphCypher::StreamQueryContext* MemgraphCypher::QueryContext::streamQuery() {
  return getRuleContext<MemgraphCypher::StreamQueryContext>(0);
}

MemgraphCypher::SettingQueryContext* MemgraphCypher::QueryContext::settingQuery() {
  return getRuleContext<MemgraphCypher::SettingQueryContext>(0);
}

MemgraphCypher::VersionQueryContext* MemgraphCypher::QueryContext::versionQuery() {
  return getRuleContext<MemgraphCypher::VersionQueryContext>(0);
}

MemgraphCypher::SnapshotQueryContext* MemgraphCypher::QueryContext::snapshotQuery() {
  return getRuleContext<MemgraphCypher::SnapshotQueryContext>(0);
}


size_t MemgraphCypher::QueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleQuery;
}

void MemgraphCypher::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void MemgraphCypher::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}


antlrcpp::Any MemgraphCypher::QueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::QueryContext* MemgraphCypher::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 4, MemgraphCypher::RuleQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(461);
      cypherQuery();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(462);
      indexQuery();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(463);
      explainQuery();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(464);
      profileQuery();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(465);
      infoQuery();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(466);
      constraintQuery();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(467);
      authQuery();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(468);
      dumpQuery();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(469);
      replicationQuery();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(470);
      lockPathQuery();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(471);
      freeMemoryQuery();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(472);
      triggerQuery();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(473);
      isolationLevelQuery();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(474);
      createSnapshotQuery();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(475);
      streamQuery();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(476);
      settingQuery();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(477);
      versionQuery();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(478);
      snapshotQuery();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AuthQueryContext ------------------------------------------------------------------

MemgraphCypher::AuthQueryContext::AuthQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CreateRoleContext* MemgraphCypher::AuthQueryContext::createRole() {
  return getRuleContext<MemgraphCypher::CreateRoleContext>(0);
}

MemgraphCypher::DropRoleContext* MemgraphCypher::AuthQueryContext::dropRole() {
  return getRuleContext<MemgraphCypher::DropRoleContext>(0);
}

MemgraphCypher::ShowRolesContext* MemgraphCypher::AuthQueryContext::showRoles() {
  return getRuleContext<MemgraphCypher::ShowRolesContext>(0);
}

MemgraphCypher::CreateUserContext* MemgraphCypher::AuthQueryContext::createUser() {
  return getRuleContext<MemgraphCypher::CreateUserContext>(0);
}

MemgraphCypher::SetPasswordContext* MemgraphCypher::AuthQueryContext::setPassword() {
  return getRuleContext<MemgraphCypher::SetPasswordContext>(0);
}

MemgraphCypher::DropUserContext* MemgraphCypher::AuthQueryContext::dropUser() {
  return getRuleContext<MemgraphCypher::DropUserContext>(0);
}

MemgraphCypher::ShowUsersContext* MemgraphCypher::AuthQueryContext::showUsers() {
  return getRuleContext<MemgraphCypher::ShowUsersContext>(0);
}

MemgraphCypher::SetRoleContext* MemgraphCypher::AuthQueryContext::setRole() {
  return getRuleContext<MemgraphCypher::SetRoleContext>(0);
}

MemgraphCypher::ClearRoleContext* MemgraphCypher::AuthQueryContext::clearRole() {
  return getRuleContext<MemgraphCypher::ClearRoleContext>(0);
}

MemgraphCypher::GrantPrivilegeContext* MemgraphCypher::AuthQueryContext::grantPrivilege() {
  return getRuleContext<MemgraphCypher::GrantPrivilegeContext>(0);
}

MemgraphCypher::DenyPrivilegeContext* MemgraphCypher::AuthQueryContext::denyPrivilege() {
  return getRuleContext<MemgraphCypher::DenyPrivilegeContext>(0);
}

MemgraphCypher::RevokePrivilegeContext* MemgraphCypher::AuthQueryContext::revokePrivilege() {
  return getRuleContext<MemgraphCypher::RevokePrivilegeContext>(0);
}

MemgraphCypher::ShowPrivilegesContext* MemgraphCypher::AuthQueryContext::showPrivileges() {
  return getRuleContext<MemgraphCypher::ShowPrivilegesContext>(0);
}

MemgraphCypher::ShowRoleForUserContext* MemgraphCypher::AuthQueryContext::showRoleForUser() {
  return getRuleContext<MemgraphCypher::ShowRoleForUserContext>(0);
}

MemgraphCypher::ShowUsersForRoleContext* MemgraphCypher::AuthQueryContext::showUsersForRole() {
  return getRuleContext<MemgraphCypher::ShowUsersForRoleContext>(0);
}


size_t MemgraphCypher::AuthQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleAuthQuery;
}

void MemgraphCypher::AuthQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAuthQuery(this);
}

void MemgraphCypher::AuthQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAuthQuery(this);
}


antlrcpp::Any MemgraphCypher::AuthQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitAuthQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::AuthQueryContext* MemgraphCypher::authQuery() {
  AuthQueryContext *_localctx = _tracker.createInstance<AuthQueryContext>(_ctx, getState());
  enterRule(_localctx, 6, MemgraphCypher::RuleAuthQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(496);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(481);
      createRole();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(482);
      dropRole();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(483);
      showRoles();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(484);
      createUser();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(485);
      setPassword();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(486);
      dropUser();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(487);
      showUsers();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(488);
      setRole();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(489);
      clearRole();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(490);
      grantPrivilege();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(491);
      denyPrivilege();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(492);
      revokePrivilege();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(493);
      showPrivileges();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(494);
      showRoleForUser();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(495);
      showUsersForRole();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReplicationQueryContext ------------------------------------------------------------------

MemgraphCypher::ReplicationQueryContext::ReplicationQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SetReplicationRoleContext* MemgraphCypher::ReplicationQueryContext::setReplicationRole() {
  return getRuleContext<MemgraphCypher::SetReplicationRoleContext>(0);
}

MemgraphCypher::ShowReplicationRoleContext* MemgraphCypher::ReplicationQueryContext::showReplicationRole() {
  return getRuleContext<MemgraphCypher::ShowReplicationRoleContext>(0);
}

MemgraphCypher::RegisterReplicaContext* MemgraphCypher::ReplicationQueryContext::registerReplica() {
  return getRuleContext<MemgraphCypher::RegisterReplicaContext>(0);
}

MemgraphCypher::DropReplicaContext* MemgraphCypher::ReplicationQueryContext::dropReplica() {
  return getRuleContext<MemgraphCypher::DropReplicaContext>(0);
}

MemgraphCypher::ShowReplicasContext* MemgraphCypher::ReplicationQueryContext::showReplicas() {
  return getRuleContext<MemgraphCypher::ShowReplicasContext>(0);
}


size_t MemgraphCypher::ReplicationQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleReplicationQuery;
}

void MemgraphCypher::ReplicationQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReplicationQuery(this);
}

void MemgraphCypher::ReplicationQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReplicationQuery(this);
}


antlrcpp::Any MemgraphCypher::ReplicationQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReplicationQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReplicationQueryContext* MemgraphCypher::replicationQuery() {
  ReplicationQueryContext *_localctx = _tracker.createInstance<ReplicationQueryContext>(_ctx, getState());
  enterRule(_localctx, 8, MemgraphCypher::RuleReplicationQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(498);
      setReplicationRole();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(499);
      showReplicationRole();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(500);
      registerReplica();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(501);
      dropReplica();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(502);
      showReplicas();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriggerQueryContext ------------------------------------------------------------------

MemgraphCypher::TriggerQueryContext::TriggerQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CreateTriggerContext* MemgraphCypher::TriggerQueryContext::createTrigger() {
  return getRuleContext<MemgraphCypher::CreateTriggerContext>(0);
}

MemgraphCypher::DropTriggerContext* MemgraphCypher::TriggerQueryContext::dropTrigger() {
  return getRuleContext<MemgraphCypher::DropTriggerContext>(0);
}

MemgraphCypher::ShowTriggersContext* MemgraphCypher::TriggerQueryContext::showTriggers() {
  return getRuleContext<MemgraphCypher::ShowTriggersContext>(0);
}


size_t MemgraphCypher::TriggerQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleTriggerQuery;
}

void MemgraphCypher::TriggerQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerQuery(this);
}

void MemgraphCypher::TriggerQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerQuery(this);
}


antlrcpp::Any MemgraphCypher::TriggerQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitTriggerQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::TriggerQueryContext* MemgraphCypher::triggerQuery() {
  TriggerQueryContext *_localctx = _tracker.createInstance<TriggerQueryContext>(_ctx, getState());
  enterRule(_localctx, 10, MemgraphCypher::RuleTriggerQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(508);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::CREATE: {
        enterOuterAlt(_localctx, 1);
        setState(505);
        createTrigger();
        break;
      }

      case MemgraphCypher::DROP: {
        enterOuterAlt(_localctx, 2);
        setState(506);
        dropTrigger();
        break;
      }

      case MemgraphCypher::SHOW: {
        enterOuterAlt(_localctx, 3);
        setState(507);
        showTriggers();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClauseContext ------------------------------------------------------------------

MemgraphCypher::ClauseContext::ClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CypherMatchContext* MemgraphCypher::ClauseContext::cypherMatch() {
  return getRuleContext<MemgraphCypher::CypherMatchContext>(0);
}

MemgraphCypher::UnwindContext* MemgraphCypher::ClauseContext::unwind() {
  return getRuleContext<MemgraphCypher::UnwindContext>(0);
}

MemgraphCypher::MergeContext* MemgraphCypher::ClauseContext::merge() {
  return getRuleContext<MemgraphCypher::MergeContext>(0);
}

MemgraphCypher::CreateContext* MemgraphCypher::ClauseContext::create() {
  return getRuleContext<MemgraphCypher::CreateContext>(0);
}

MemgraphCypher::SetContext* MemgraphCypher::ClauseContext::set() {
  return getRuleContext<MemgraphCypher::SetContext>(0);
}

MemgraphCypher::CypherDeleteContext* MemgraphCypher::ClauseContext::cypherDelete() {
  return getRuleContext<MemgraphCypher::CypherDeleteContext>(0);
}

MemgraphCypher::RemoveContext* MemgraphCypher::ClauseContext::remove() {
  return getRuleContext<MemgraphCypher::RemoveContext>(0);
}

MemgraphCypher::WithContext* MemgraphCypher::ClauseContext::with() {
  return getRuleContext<MemgraphCypher::WithContext>(0);
}

MemgraphCypher::CypherReturnContext* MemgraphCypher::ClauseContext::cypherReturn() {
  return getRuleContext<MemgraphCypher::CypherReturnContext>(0);
}

MemgraphCypher::CallProcedureContext* MemgraphCypher::ClauseContext::callProcedure() {
  return getRuleContext<MemgraphCypher::CallProcedureContext>(0);
}

MemgraphCypher::LoadCsvContext* MemgraphCypher::ClauseContext::loadCsv() {
  return getRuleContext<MemgraphCypher::LoadCsvContext>(0);
}


size_t MemgraphCypher::ClauseContext::getRuleIndex() const {
  return MemgraphCypher::RuleClause;
}

void MemgraphCypher::ClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClause(this);
}

void MemgraphCypher::ClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClause(this);
}


antlrcpp::Any MemgraphCypher::ClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitClause(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ClauseContext* MemgraphCypher::clause() {
  ClauseContext *_localctx = _tracker.createInstance<ClauseContext>(_ctx, getState());
  enterRule(_localctx, 12, MemgraphCypher::RuleClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::MATCH:
      case MemgraphCypher::OPTIONAL: {
        enterOuterAlt(_localctx, 1);
        setState(510);
        cypherMatch();
        break;
      }

      case MemgraphCypher::UNWIND: {
        enterOuterAlt(_localctx, 2);
        setState(511);
        unwind();
        break;
      }

      case MemgraphCypher::MERGE: {
        enterOuterAlt(_localctx, 3);
        setState(512);
        merge();
        break;
      }

      case MemgraphCypher::CREATE: {
        enterOuterAlt(_localctx, 4);
        setState(513);
        create();
        break;
      }

      case MemgraphCypher::SET: {
        enterOuterAlt(_localctx, 5);
        setState(514);
        set();
        break;
      }

      case MemgraphCypher::DELETE:
      case MemgraphCypher::DETACH: {
        enterOuterAlt(_localctx, 6);
        setState(515);
        cypherDelete();
        break;
      }

      case MemgraphCypher::REMOVE: {
        enterOuterAlt(_localctx, 7);
        setState(516);
        remove();
        break;
      }

      case MemgraphCypher::WITH: {
        enterOuterAlt(_localctx, 8);
        setState(517);
        with();
        break;
      }

      case MemgraphCypher::RETURN: {
        enterOuterAlt(_localctx, 9);
        setState(518);
        cypherReturn();
        break;
      }

      case MemgraphCypher::CALL: {
        enterOuterAlt(_localctx, 10);
        setState(519);
        callProcedure();
        break;
      }

      case MemgraphCypher::LOAD: {
        enterOuterAlt(_localctx, 11);
        setState(520);
        loadCsv();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StreamQueryContext ------------------------------------------------------------------

MemgraphCypher::StreamQueryContext::StreamQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CheckStreamContext* MemgraphCypher::StreamQueryContext::checkStream() {
  return getRuleContext<MemgraphCypher::CheckStreamContext>(0);
}

MemgraphCypher::CreateStreamContext* MemgraphCypher::StreamQueryContext::createStream() {
  return getRuleContext<MemgraphCypher::CreateStreamContext>(0);
}

MemgraphCypher::DropStreamContext* MemgraphCypher::StreamQueryContext::dropStream() {
  return getRuleContext<MemgraphCypher::DropStreamContext>(0);
}

MemgraphCypher::StartStreamContext* MemgraphCypher::StreamQueryContext::startStream() {
  return getRuleContext<MemgraphCypher::StartStreamContext>(0);
}

MemgraphCypher::StartAllStreamsContext* MemgraphCypher::StreamQueryContext::startAllStreams() {
  return getRuleContext<MemgraphCypher::StartAllStreamsContext>(0);
}

MemgraphCypher::StopStreamContext* MemgraphCypher::StreamQueryContext::stopStream() {
  return getRuleContext<MemgraphCypher::StopStreamContext>(0);
}

MemgraphCypher::StopAllStreamsContext* MemgraphCypher::StreamQueryContext::stopAllStreams() {
  return getRuleContext<MemgraphCypher::StopAllStreamsContext>(0);
}

MemgraphCypher::ShowStreamsContext* MemgraphCypher::StreamQueryContext::showStreams() {
  return getRuleContext<MemgraphCypher::ShowStreamsContext>(0);
}


size_t MemgraphCypher::StreamQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleStreamQuery;
}

void MemgraphCypher::StreamQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStreamQuery(this);
}

void MemgraphCypher::StreamQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStreamQuery(this);
}


antlrcpp::Any MemgraphCypher::StreamQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStreamQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StreamQueryContext* MemgraphCypher::streamQuery() {
  StreamQueryContext *_localctx = _tracker.createInstance<StreamQueryContext>(_ctx, getState());
  enterRule(_localctx, 14, MemgraphCypher::RuleStreamQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(531);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(523);
      checkStream();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(524);
      createStream();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(525);
      dropStream();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(526);
      startStream();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(527);
      startAllStreams();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(528);
      stopStream();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(529);
      stopAllStreams();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(530);
      showStreams();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingQueryContext ------------------------------------------------------------------

MemgraphCypher::SettingQueryContext::SettingQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SetSettingContext* MemgraphCypher::SettingQueryContext::setSetting() {
  return getRuleContext<MemgraphCypher::SetSettingContext>(0);
}

MemgraphCypher::ShowSettingContext* MemgraphCypher::SettingQueryContext::showSetting() {
  return getRuleContext<MemgraphCypher::ShowSettingContext>(0);
}

MemgraphCypher::ShowSettingsContext* MemgraphCypher::SettingQueryContext::showSettings() {
  return getRuleContext<MemgraphCypher::ShowSettingsContext>(0);
}


size_t MemgraphCypher::SettingQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleSettingQuery;
}

void MemgraphCypher::SettingQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingQuery(this);
}

void MemgraphCypher::SettingQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingQuery(this);
}


antlrcpp::Any MemgraphCypher::SettingQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSettingQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SettingQueryContext* MemgraphCypher::settingQuery() {
  SettingQueryContext *_localctx = _tracker.createInstance<SettingQueryContext>(_ctx, getState());
  enterRule(_localctx, 16, MemgraphCypher::RuleSettingQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(533);
      setSetting();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(534);
      showSetting();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(535);
      showSettings();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoadCsvContext ------------------------------------------------------------------

MemgraphCypher::LoadCsvContext::LoadCsvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::LOAD() {
  return getToken(MemgraphCypher::LOAD, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::CSV() {
  return getToken(MemgraphCypher::CSV, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::FROM() {
  return getToken(MemgraphCypher::FROM, 0);
}

MemgraphCypher::CsvFileContext* MemgraphCypher::LoadCsvContext::csvFile() {
  return getRuleContext<MemgraphCypher::CsvFileContext>(0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::HEADER() {
  return getToken(MemgraphCypher::HEADER, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

MemgraphCypher::RowVarContext* MemgraphCypher::LoadCsvContext::rowVar() {
  return getRuleContext<MemgraphCypher::RowVarContext>(0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::NO() {
  return getToken(MemgraphCypher::NO, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::IGNORE() {
  return getToken(MemgraphCypher::IGNORE, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::BAD() {
  return getToken(MemgraphCypher::BAD, 0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::DELIMITER() {
  return getToken(MemgraphCypher::DELIMITER, 0);
}

MemgraphCypher::DelimiterContext* MemgraphCypher::LoadCsvContext::delimiter() {
  return getRuleContext<MemgraphCypher::DelimiterContext>(0);
}

tree::TerminalNode* MemgraphCypher::LoadCsvContext::QUOTE() {
  return getToken(MemgraphCypher::QUOTE, 0);
}

MemgraphCypher::QuoteContext* MemgraphCypher::LoadCsvContext::quote() {
  return getRuleContext<MemgraphCypher::QuoteContext>(0);
}


size_t MemgraphCypher::LoadCsvContext::getRuleIndex() const {
  return MemgraphCypher::RuleLoadCsv;
}

void MemgraphCypher::LoadCsvContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoadCsv(this);
}

void MemgraphCypher::LoadCsvContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoadCsv(this);
}


antlrcpp::Any MemgraphCypher::LoadCsvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLoadCsv(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LoadCsvContext* MemgraphCypher::loadCsv() {
  LoadCsvContext *_localctx = _tracker.createInstance<LoadCsvContext>(_ctx, getState());
  enterRule(_localctx, 18, MemgraphCypher::RuleLoadCsv);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    match(MemgraphCypher::LOAD);
    setState(539);
    match(MemgraphCypher::CSV);
    setState(540);
    match(MemgraphCypher::FROM);
    setState(541);
    csvFile();
    setState(542);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::NO || _la == MemgraphCypher::WITH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(543);
    match(MemgraphCypher::HEADER);
    setState(546);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::IGNORE) {
      setState(544);
      match(MemgraphCypher::IGNORE);
      setState(545);
      match(MemgraphCypher::BAD);
    }
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::DELIMITER) {
      setState(548);
      match(MemgraphCypher::DELIMITER);
      setState(549);
      delimiter();
    }
    setState(554);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::QUOTE) {
      setState(552);
      match(MemgraphCypher::QUOTE);
      setState(553);
      quote();
    }
    setState(556);
    match(MemgraphCypher::AS);
    setState(557);
    rowVar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CsvFileContext ------------------------------------------------------------------

MemgraphCypher::CsvFileContext::CsvFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::CsvFileContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::CsvFileContext::getRuleIndex() const {
  return MemgraphCypher::RuleCsvFile;
}

void MemgraphCypher::CsvFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCsvFile(this);
}

void MemgraphCypher::CsvFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCsvFile(this);
}


antlrcpp::Any MemgraphCypher::CsvFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCsvFile(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CsvFileContext* MemgraphCypher::csvFile() {
  CsvFileContext *_localctx = _tracker.createInstance<CsvFileContext>(_ctx, getState());
  enterRule(_localctx, 20, MemgraphCypher::RuleCsvFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DelimiterContext ------------------------------------------------------------------

MemgraphCypher::DelimiterContext::DelimiterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::DelimiterContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::DelimiterContext::getRuleIndex() const {
  return MemgraphCypher::RuleDelimiter;
}

void MemgraphCypher::DelimiterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelimiter(this);
}

void MemgraphCypher::DelimiterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelimiter(this);
}


antlrcpp::Any MemgraphCypher::DelimiterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDelimiter(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DelimiterContext* MemgraphCypher::delimiter() {
  DelimiterContext *_localctx = _tracker.createInstance<DelimiterContext>(_ctx, getState());
  enterRule(_localctx, 22, MemgraphCypher::RuleDelimiter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(561);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuoteContext ------------------------------------------------------------------

MemgraphCypher::QuoteContext::QuoteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::QuoteContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::QuoteContext::getRuleIndex() const {
  return MemgraphCypher::RuleQuote;
}

void MemgraphCypher::QuoteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuote(this);
}

void MemgraphCypher::QuoteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuote(this);
}


antlrcpp::Any MemgraphCypher::QuoteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitQuote(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::QuoteContext* MemgraphCypher::quote() {
  QuoteContext *_localctx = _tracker.createInstance<QuoteContext>(_ctx, getState());
  enterRule(_localctx, 24, MemgraphCypher::RuleQuote);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(563);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowVarContext ------------------------------------------------------------------

MemgraphCypher::RowVarContext::RowVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::VariableContext* MemgraphCypher::RowVarContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}


size_t MemgraphCypher::RowVarContext::getRuleIndex() const {
  return MemgraphCypher::RuleRowVar;
}

void MemgraphCypher::RowVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRowVar(this);
}

void MemgraphCypher::RowVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRowVar(this);
}


antlrcpp::Any MemgraphCypher::RowVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRowVar(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RowVarContext* MemgraphCypher::rowVar() {
  RowVarContext *_localctx = _tracker.createInstance<RowVarContext>(_ctx, getState());
  enterRule(_localctx, 26, MemgraphCypher::RuleRowVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UserOrRoleNameContext ------------------------------------------------------------------

MemgraphCypher::UserOrRoleNameContext::UserOrRoleNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::UserOrRoleNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::UserOrRoleNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleUserOrRoleName;
}

void MemgraphCypher::UserOrRoleNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUserOrRoleName(this);
}

void MemgraphCypher::UserOrRoleNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUserOrRoleName(this);
}


antlrcpp::Any MemgraphCypher::UserOrRoleNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitUserOrRoleName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::userOrRoleName() {
  UserOrRoleNameContext *_localctx = _tracker.createInstance<UserOrRoleNameContext>(_ctx, getState());
  enterRule(_localctx, 28, MemgraphCypher::RuleUserOrRoleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(567);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateRoleContext ------------------------------------------------------------------

MemgraphCypher::CreateRoleContext::CreateRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CreateRoleContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::CreateRoleContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::CreateRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateRole;
}

void MemgraphCypher::CreateRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateRole(this);
}

void MemgraphCypher::CreateRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateRole(this);
}


antlrcpp::Any MemgraphCypher::CreateRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateRoleContext* MemgraphCypher::createRole() {
  CreateRoleContext *_localctx = _tracker.createInstance<CreateRoleContext>(_ctx, getState());
  enterRule(_localctx, 30, MemgraphCypher::RuleCreateRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    match(MemgraphCypher::CREATE);
    setState(570);
    match(MemgraphCypher::ROLE);
    setState(571);
    dynamic_cast<CreateRoleContext *>(_localctx)->role = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropRoleContext ------------------------------------------------------------------

MemgraphCypher::DropRoleContext::DropRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropRoleContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::DropRoleContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::DropRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropRole;
}

void MemgraphCypher::DropRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropRole(this);
}

void MemgraphCypher::DropRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropRole(this);
}


antlrcpp::Any MemgraphCypher::DropRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropRoleContext* MemgraphCypher::dropRole() {
  DropRoleContext *_localctx = _tracker.createInstance<DropRoleContext>(_ctx, getState());
  enterRule(_localctx, 32, MemgraphCypher::RuleDropRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(MemgraphCypher::DROP);
    setState(574);
    match(MemgraphCypher::ROLE);
    setState(575);
    dynamic_cast<DropRoleContext *>(_localctx)->role = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowRolesContext ------------------------------------------------------------------

MemgraphCypher::ShowRolesContext::ShowRolesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowRolesContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowRolesContext::ROLES() {
  return getToken(MemgraphCypher::ROLES, 0);
}


size_t MemgraphCypher::ShowRolesContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowRoles;
}

void MemgraphCypher::ShowRolesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowRoles(this);
}

void MemgraphCypher::ShowRolesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowRoles(this);
}


antlrcpp::Any MemgraphCypher::ShowRolesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowRoles(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowRolesContext* MemgraphCypher::showRoles() {
  ShowRolesContext *_localctx = _tracker.createInstance<ShowRolesContext>(_ctx, getState());
  enterRule(_localctx, 34, MemgraphCypher::RuleShowRoles);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    match(MemgraphCypher::SHOW);
    setState(578);
    match(MemgraphCypher::ROLES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateUserContext ------------------------------------------------------------------

MemgraphCypher::CreateUserContext::CreateUserContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CreateUserContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateUserContext::USER() {
  return getToken(MemgraphCypher::USER, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::CreateUserContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CreateUserContext::IDENTIFIED() {
  return getToken(MemgraphCypher::IDENTIFIED, 0);
}

tree::TerminalNode* MemgraphCypher::CreateUserContext::BY() {
  return getToken(MemgraphCypher::BY, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::CreateUserContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::CreateUserContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateUser;
}

void MemgraphCypher::CreateUserContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateUser(this);
}

void MemgraphCypher::CreateUserContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateUser(this);
}


antlrcpp::Any MemgraphCypher::CreateUserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateUser(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateUserContext* MemgraphCypher::createUser() {
  CreateUserContext *_localctx = _tracker.createInstance<CreateUserContext>(_ctx, getState());
  enterRule(_localctx, 36, MemgraphCypher::RuleCreateUser);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(580);
    match(MemgraphCypher::CREATE);
    setState(581);
    match(MemgraphCypher::USER);
    setState(582);
    dynamic_cast<CreateUserContext *>(_localctx)->user = userOrRoleName();
    setState(586);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::IDENTIFIED) {
      setState(583);
      match(MemgraphCypher::IDENTIFIED);
      setState(584);
      match(MemgraphCypher::BY);
      setState(585);
      dynamic_cast<CreateUserContext *>(_localctx)->password = literal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetPasswordContext ------------------------------------------------------------------

MemgraphCypher::SetPasswordContext::SetPasswordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SetPasswordContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::SetPasswordContext::PASSWORD() {
  return getToken(MemgraphCypher::PASSWORD, 0);
}

tree::TerminalNode* MemgraphCypher::SetPasswordContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

tree::TerminalNode* MemgraphCypher::SetPasswordContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::SetPasswordContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::SetPasswordContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::SetPasswordContext::getRuleIndex() const {
  return MemgraphCypher::RuleSetPassword;
}

void MemgraphCypher::SetPasswordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetPassword(this);
}

void MemgraphCypher::SetPasswordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetPassword(this);
}


antlrcpp::Any MemgraphCypher::SetPasswordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSetPassword(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetPasswordContext* MemgraphCypher::setPassword() {
  SetPasswordContext *_localctx = _tracker.createInstance<SetPasswordContext>(_ctx, getState());
  enterRule(_localctx, 38, MemgraphCypher::RuleSetPassword);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(588);
    match(MemgraphCypher::SET);
    setState(589);
    match(MemgraphCypher::PASSWORD);
    setState(590);
    match(MemgraphCypher::FOR);
    setState(591);
    dynamic_cast<SetPasswordContext *>(_localctx)->user = userOrRoleName();
    setState(592);
    match(MemgraphCypher::TO);
    setState(593);
    dynamic_cast<SetPasswordContext *>(_localctx)->password = literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropUserContext ------------------------------------------------------------------

MemgraphCypher::DropUserContext::DropUserContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropUserContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropUserContext::USER() {
  return getToken(MemgraphCypher::USER, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::DropUserContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::DropUserContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropUser;
}

void MemgraphCypher::DropUserContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropUser(this);
}

void MemgraphCypher::DropUserContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropUser(this);
}


antlrcpp::Any MemgraphCypher::DropUserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropUser(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropUserContext* MemgraphCypher::dropUser() {
  DropUserContext *_localctx = _tracker.createInstance<DropUserContext>(_ctx, getState());
  enterRule(_localctx, 40, MemgraphCypher::RuleDropUser);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(MemgraphCypher::DROP);
    setState(596);
    match(MemgraphCypher::USER);
    setState(597);
    dynamic_cast<DropUserContext *>(_localctx)->user = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowUsersContext ------------------------------------------------------------------

MemgraphCypher::ShowUsersContext::ShowUsersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowUsersContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowUsersContext::USERS() {
  return getToken(MemgraphCypher::USERS, 0);
}


size_t MemgraphCypher::ShowUsersContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowUsers;
}

void MemgraphCypher::ShowUsersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowUsers(this);
}

void MemgraphCypher::ShowUsersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowUsers(this);
}


antlrcpp::Any MemgraphCypher::ShowUsersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowUsers(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowUsersContext* MemgraphCypher::showUsers() {
  ShowUsersContext *_localctx = _tracker.createInstance<ShowUsersContext>(_ctx, getState());
  enterRule(_localctx, 42, MemgraphCypher::RuleShowUsers);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    match(MemgraphCypher::SHOW);
    setState(600);
    match(MemgraphCypher::USERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetRoleContext ------------------------------------------------------------------

MemgraphCypher::SetRoleContext::SetRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SetRoleContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::SetRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

tree::TerminalNode* MemgraphCypher::SetRoleContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

tree::TerminalNode* MemgraphCypher::SetRoleContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

std::vector<MemgraphCypher::UserOrRoleNameContext *> MemgraphCypher::SetRoleContext::userOrRoleName() {
  return getRuleContexts<MemgraphCypher::UserOrRoleNameContext>();
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::SetRoleContext::userOrRoleName(size_t i) {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(i);
}


size_t MemgraphCypher::SetRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleSetRole;
}

void MemgraphCypher::SetRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetRole(this);
}

void MemgraphCypher::SetRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetRole(this);
}


antlrcpp::Any MemgraphCypher::SetRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSetRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetRoleContext* MemgraphCypher::setRole() {
  SetRoleContext *_localctx = _tracker.createInstance<SetRoleContext>(_ctx, getState());
  enterRule(_localctx, 44, MemgraphCypher::RuleSetRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(MemgraphCypher::SET);
    setState(603);
    match(MemgraphCypher::ROLE);
    setState(604);
    match(MemgraphCypher::FOR);
    setState(605);
    dynamic_cast<SetRoleContext *>(_localctx)->user = userOrRoleName();
    setState(606);
    match(MemgraphCypher::TO);
    setState(607);
    dynamic_cast<SetRoleContext *>(_localctx)->role = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClearRoleContext ------------------------------------------------------------------

MemgraphCypher::ClearRoleContext::ClearRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ClearRoleContext::CLEAR() {
  return getToken(MemgraphCypher::CLEAR, 0);
}

tree::TerminalNode* MemgraphCypher::ClearRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

tree::TerminalNode* MemgraphCypher::ClearRoleContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::ClearRoleContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::ClearRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleClearRole;
}

void MemgraphCypher::ClearRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClearRole(this);
}

void MemgraphCypher::ClearRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClearRole(this);
}


antlrcpp::Any MemgraphCypher::ClearRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitClearRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ClearRoleContext* MemgraphCypher::clearRole() {
  ClearRoleContext *_localctx = _tracker.createInstance<ClearRoleContext>(_ctx, getState());
  enterRule(_localctx, 46, MemgraphCypher::RuleClearRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    match(MemgraphCypher::CLEAR);
    setState(610);
    match(MemgraphCypher::ROLE);
    setState(611);
    match(MemgraphCypher::FOR);
    setState(612);
    dynamic_cast<ClearRoleContext *>(_localctx)->user = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GrantPrivilegeContext ------------------------------------------------------------------

MemgraphCypher::GrantPrivilegeContext::GrantPrivilegeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::GrantPrivilegeContext::GRANT() {
  return getToken(MemgraphCypher::GRANT, 0);
}

tree::TerminalNode* MemgraphCypher::GrantPrivilegeContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::GrantPrivilegeContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::GrantPrivilegeContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::GrantPrivilegeContext::PRIVILEGES() {
  return getToken(MemgraphCypher::PRIVILEGES, 0);
}

MemgraphCypher::PrivilegeListContext* MemgraphCypher::GrantPrivilegeContext::privilegeList() {
  return getRuleContext<MemgraphCypher::PrivilegeListContext>(0);
}


size_t MemgraphCypher::GrantPrivilegeContext::getRuleIndex() const {
  return MemgraphCypher::RuleGrantPrivilege;
}

void MemgraphCypher::GrantPrivilegeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrantPrivilege(this);
}

void MemgraphCypher::GrantPrivilegeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrantPrivilege(this);
}


antlrcpp::Any MemgraphCypher::GrantPrivilegeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitGrantPrivilege(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::GrantPrivilegeContext* MemgraphCypher::grantPrivilege() {
  GrantPrivilegeContext *_localctx = _tracker.createInstance<GrantPrivilegeContext>(_ctx, getState());
  enterRule(_localctx, 48, MemgraphCypher::RuleGrantPrivilege);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    match(MemgraphCypher::GRANT);
    setState(618);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::ALL: {
        setState(615);
        match(MemgraphCypher::ALL);
        setState(616);
        match(MemgraphCypher::PRIVILEGES);
        break;
      }

      case MemgraphCypher::AUTH:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::DURABILITY:
      case MemgraphCypher::FREE_MEMORY:
      case MemgraphCypher::MODULE_READ:
      case MemgraphCypher::MODULE_WRITE:
      case MemgraphCypher::READ_FILE:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::WEBSOCKET:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::SET: {
        setState(617);
        dynamic_cast<GrantPrivilegeContext *>(_localctx)->privileges = privilegeList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(620);
    match(MemgraphCypher::TO);
    setState(621);
    dynamic_cast<GrantPrivilegeContext *>(_localctx)->userOrRole = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DenyPrivilegeContext ------------------------------------------------------------------

MemgraphCypher::DenyPrivilegeContext::DenyPrivilegeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DenyPrivilegeContext::DENY() {
  return getToken(MemgraphCypher::DENY, 0);
}

tree::TerminalNode* MemgraphCypher::DenyPrivilegeContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::DenyPrivilegeContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::DenyPrivilegeContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::DenyPrivilegeContext::PRIVILEGES() {
  return getToken(MemgraphCypher::PRIVILEGES, 0);
}

MemgraphCypher::PrivilegeListContext* MemgraphCypher::DenyPrivilegeContext::privilegeList() {
  return getRuleContext<MemgraphCypher::PrivilegeListContext>(0);
}


size_t MemgraphCypher::DenyPrivilegeContext::getRuleIndex() const {
  return MemgraphCypher::RuleDenyPrivilege;
}

void MemgraphCypher::DenyPrivilegeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDenyPrivilege(this);
}

void MemgraphCypher::DenyPrivilegeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDenyPrivilege(this);
}


antlrcpp::Any MemgraphCypher::DenyPrivilegeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDenyPrivilege(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DenyPrivilegeContext* MemgraphCypher::denyPrivilege() {
  DenyPrivilegeContext *_localctx = _tracker.createInstance<DenyPrivilegeContext>(_ctx, getState());
  enterRule(_localctx, 50, MemgraphCypher::RuleDenyPrivilege);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    match(MemgraphCypher::DENY);
    setState(627);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::ALL: {
        setState(624);
        match(MemgraphCypher::ALL);
        setState(625);
        match(MemgraphCypher::PRIVILEGES);
        break;
      }

      case MemgraphCypher::AUTH:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::DURABILITY:
      case MemgraphCypher::FREE_MEMORY:
      case MemgraphCypher::MODULE_READ:
      case MemgraphCypher::MODULE_WRITE:
      case MemgraphCypher::READ_FILE:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::WEBSOCKET:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::SET: {
        setState(626);
        dynamic_cast<DenyPrivilegeContext *>(_localctx)->privileges = privilegeList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(629);
    match(MemgraphCypher::TO);
    setState(630);
    dynamic_cast<DenyPrivilegeContext *>(_localctx)->userOrRole = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RevokePrivilegeContext ------------------------------------------------------------------

MemgraphCypher::RevokePrivilegeContext::RevokePrivilegeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RevokePrivilegeContext::REVOKE() {
  return getToken(MemgraphCypher::REVOKE, 0);
}

tree::TerminalNode* MemgraphCypher::RevokePrivilegeContext::FROM() {
  return getToken(MemgraphCypher::FROM, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::RevokePrivilegeContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::RevokePrivilegeContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::RevokePrivilegeContext::PRIVILEGES() {
  return getToken(MemgraphCypher::PRIVILEGES, 0);
}

MemgraphCypher::PrivilegeListContext* MemgraphCypher::RevokePrivilegeContext::privilegeList() {
  return getRuleContext<MemgraphCypher::PrivilegeListContext>(0);
}


size_t MemgraphCypher::RevokePrivilegeContext::getRuleIndex() const {
  return MemgraphCypher::RuleRevokePrivilege;
}

void MemgraphCypher::RevokePrivilegeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRevokePrivilege(this);
}

void MemgraphCypher::RevokePrivilegeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRevokePrivilege(this);
}


antlrcpp::Any MemgraphCypher::RevokePrivilegeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRevokePrivilege(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RevokePrivilegeContext* MemgraphCypher::revokePrivilege() {
  RevokePrivilegeContext *_localctx = _tracker.createInstance<RevokePrivilegeContext>(_ctx, getState());
  enterRule(_localctx, 52, MemgraphCypher::RuleRevokePrivilege);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(632);
    match(MemgraphCypher::REVOKE);
    setState(636);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::ALL: {
        setState(633);
        match(MemgraphCypher::ALL);
        setState(634);
        match(MemgraphCypher::PRIVILEGES);
        break;
      }

      case MemgraphCypher::AUTH:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::DURABILITY:
      case MemgraphCypher::FREE_MEMORY:
      case MemgraphCypher::MODULE_READ:
      case MemgraphCypher::MODULE_WRITE:
      case MemgraphCypher::READ_FILE:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::WEBSOCKET:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::SET: {
        setState(635);
        dynamic_cast<RevokePrivilegeContext *>(_localctx)->privileges = privilegeList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(638);
    match(MemgraphCypher::FROM);
    setState(639);
    dynamic_cast<RevokePrivilegeContext *>(_localctx)->userOrRole = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrivilegeContext ------------------------------------------------------------------

MemgraphCypher::PrivilegeContext::PrivilegeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::DELETE() {
  return getToken(MemgraphCypher::DELETE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::MATCH() {
  return getToken(MemgraphCypher::MATCH, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::MERGE() {
  return getToken(MemgraphCypher::MERGE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::REMOVE() {
  return getToken(MemgraphCypher::REMOVE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::INDEX() {
  return getToken(MemgraphCypher::INDEX, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::STATS() {
  return getToken(MemgraphCypher::STATS, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::AUTH() {
  return getToken(MemgraphCypher::AUTH, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::CONSTRAINT() {
  return getToken(MemgraphCypher::CONSTRAINT, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::DUMP() {
  return getToken(MemgraphCypher::DUMP, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::REPLICATION() {
  return getToken(MemgraphCypher::REPLICATION, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::READ_FILE() {
  return getToken(MemgraphCypher::READ_FILE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::FREE_MEMORY() {
  return getToken(MemgraphCypher::FREE_MEMORY, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::TRIGGER() {
  return getToken(MemgraphCypher::TRIGGER, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::CONFIG() {
  return getToken(MemgraphCypher::CONFIG, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::DURABILITY() {
  return getToken(MemgraphCypher::DURABILITY, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::MODULE_READ() {
  return getToken(MemgraphCypher::MODULE_READ, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::MODULE_WRITE() {
  return getToken(MemgraphCypher::MODULE_WRITE, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::WEBSOCKET() {
  return getToken(MemgraphCypher::WEBSOCKET, 0);
}

tree::TerminalNode* MemgraphCypher::PrivilegeContext::SNAPSHOT() {
  return getToken(MemgraphCypher::SNAPSHOT, 0);
}


size_t MemgraphCypher::PrivilegeContext::getRuleIndex() const {
  return MemgraphCypher::RulePrivilege;
}

void MemgraphCypher::PrivilegeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrivilege(this);
}

void MemgraphCypher::PrivilegeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrivilege(this);
}


antlrcpp::Any MemgraphCypher::PrivilegeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPrivilege(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PrivilegeContext* MemgraphCypher::privilege() {
  PrivilegeContext *_localctx = _tracker.createInstance<PrivilegeContext>(_ctx, getState());
  enterRule(_localctx, 54, MemgraphCypher::RulePrivilege);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::DURABILITY)
      | (1ULL << MemgraphCypher::FREE_MEMORY)
      | (1ULL << MemgraphCypher::MODULE_READ)
      | (1ULL << MemgraphCypher::MODULE_WRITE)
      | (1ULL << MemgraphCypher::READ_FILE)
      | (1ULL << MemgraphCypher::REPLICATION))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (MemgraphCypher::SNAPSHOT - 69))
      | (1ULL << (MemgraphCypher::STATS - 69))
      | (1ULL << (MemgraphCypher::STREAM - 69))
      | (1ULL << (MemgraphCypher::TRIGGER - 69))
      | (1ULL << (MemgraphCypher::WEBSOCKET - 69)))) != 0) || ((((_la - 134) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 134)) & ((1ULL << (MemgraphCypher::CONSTRAINT - 134))
      | (1ULL << (MemgraphCypher::CREATE - 134))
      | (1ULL << (MemgraphCypher::DELETE - 134))
      | (1ULL << (MemgraphCypher::INDEX - 134))
      | (1ULL << (MemgraphCypher::MATCH - 134))
      | (1ULL << (MemgraphCypher::MERGE - 134))
      | (1ULL << (MemgraphCypher::REMOVE - 134))
      | (1ULL << (MemgraphCypher::SET - 134)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrivilegeListContext ------------------------------------------------------------------

MemgraphCypher::PrivilegeListContext::PrivilegeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::PrivilegeContext *> MemgraphCypher::PrivilegeListContext::privilege() {
  return getRuleContexts<MemgraphCypher::PrivilegeContext>();
}

MemgraphCypher::PrivilegeContext* MemgraphCypher::PrivilegeListContext::privilege(size_t i) {
  return getRuleContext<MemgraphCypher::PrivilegeContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::PrivilegeListContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::PrivilegeListContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::PrivilegeListContext::getRuleIndex() const {
  return MemgraphCypher::RulePrivilegeList;
}

void MemgraphCypher::PrivilegeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrivilegeList(this);
}

void MemgraphCypher::PrivilegeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrivilegeList(this);
}


antlrcpp::Any MemgraphCypher::PrivilegeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPrivilegeList(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PrivilegeListContext* MemgraphCypher::privilegeList() {
  PrivilegeListContext *_localctx = _tracker.createInstance<PrivilegeListContext>(_ctx, getState());
  enterRule(_localctx, 56, MemgraphCypher::RulePrivilegeList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(643);
    privilege();
    setState(648);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(644);
      match(MemgraphCypher::COMMA);
      setState(645);
      privilege();
      setState(650);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowPrivilegesContext ------------------------------------------------------------------

MemgraphCypher::ShowPrivilegesContext::ShowPrivilegesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowPrivilegesContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowPrivilegesContext::PRIVILEGES() {
  return getToken(MemgraphCypher::PRIVILEGES, 0);
}

tree::TerminalNode* MemgraphCypher::ShowPrivilegesContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::ShowPrivilegesContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::ShowPrivilegesContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowPrivileges;
}

void MemgraphCypher::ShowPrivilegesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowPrivileges(this);
}

void MemgraphCypher::ShowPrivilegesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowPrivileges(this);
}


antlrcpp::Any MemgraphCypher::ShowPrivilegesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowPrivileges(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowPrivilegesContext* MemgraphCypher::showPrivileges() {
  ShowPrivilegesContext *_localctx = _tracker.createInstance<ShowPrivilegesContext>(_ctx, getState());
  enterRule(_localctx, 58, MemgraphCypher::RuleShowPrivileges);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(651);
    match(MemgraphCypher::SHOW);
    setState(652);
    match(MemgraphCypher::PRIVILEGES);
    setState(653);
    match(MemgraphCypher::FOR);
    setState(654);
    dynamic_cast<ShowPrivilegesContext *>(_localctx)->userOrRole = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowRoleForUserContext ------------------------------------------------------------------

MemgraphCypher::ShowRoleForUserContext::ShowRoleForUserContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowRoleForUserContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowRoleForUserContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

tree::TerminalNode* MemgraphCypher::ShowRoleForUserContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::ShowRoleForUserContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::ShowRoleForUserContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowRoleForUser;
}

void MemgraphCypher::ShowRoleForUserContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowRoleForUser(this);
}

void MemgraphCypher::ShowRoleForUserContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowRoleForUser(this);
}


antlrcpp::Any MemgraphCypher::ShowRoleForUserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowRoleForUser(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowRoleForUserContext* MemgraphCypher::showRoleForUser() {
  ShowRoleForUserContext *_localctx = _tracker.createInstance<ShowRoleForUserContext>(_ctx, getState());
  enterRule(_localctx, 60, MemgraphCypher::RuleShowRoleForUser);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(656);
    match(MemgraphCypher::SHOW);
    setState(657);
    match(MemgraphCypher::ROLE);
    setState(658);
    match(MemgraphCypher::FOR);
    setState(659);
    dynamic_cast<ShowRoleForUserContext *>(_localctx)->user = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowUsersForRoleContext ------------------------------------------------------------------

MemgraphCypher::ShowUsersForRoleContext::ShowUsersForRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowUsersForRoleContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowUsersForRoleContext::USERS() {
  return getToken(MemgraphCypher::USERS, 0);
}

tree::TerminalNode* MemgraphCypher::ShowUsersForRoleContext::FOR() {
  return getToken(MemgraphCypher::FOR, 0);
}

MemgraphCypher::UserOrRoleNameContext* MemgraphCypher::ShowUsersForRoleContext::userOrRoleName() {
  return getRuleContext<MemgraphCypher::UserOrRoleNameContext>(0);
}


size_t MemgraphCypher::ShowUsersForRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowUsersForRole;
}

void MemgraphCypher::ShowUsersForRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowUsersForRole(this);
}

void MemgraphCypher::ShowUsersForRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowUsersForRole(this);
}


antlrcpp::Any MemgraphCypher::ShowUsersForRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowUsersForRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowUsersForRoleContext* MemgraphCypher::showUsersForRole() {
  ShowUsersForRoleContext *_localctx = _tracker.createInstance<ShowUsersForRoleContext>(_ctx, getState());
  enterRule(_localctx, 62, MemgraphCypher::RuleShowUsersForRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(661);
    match(MemgraphCypher::SHOW);
    setState(662);
    match(MemgraphCypher::USERS);
    setState(663);
    match(MemgraphCypher::FOR);
    setState(664);
    dynamic_cast<ShowUsersForRoleContext *>(_localctx)->role = userOrRoleName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DumpQueryContext ------------------------------------------------------------------

MemgraphCypher::DumpQueryContext::DumpQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DumpQueryContext::DUMP() {
  return getToken(MemgraphCypher::DUMP, 0);
}

tree::TerminalNode* MemgraphCypher::DumpQueryContext::DATABASE() {
  return getToken(MemgraphCypher::DATABASE, 0);
}


size_t MemgraphCypher::DumpQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleDumpQuery;
}

void MemgraphCypher::DumpQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDumpQuery(this);
}

void MemgraphCypher::DumpQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDumpQuery(this);
}


antlrcpp::Any MemgraphCypher::DumpQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDumpQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DumpQueryContext* MemgraphCypher::dumpQuery() {
  DumpQueryContext *_localctx = _tracker.createInstance<DumpQueryContext>(_ctx, getState());
  enterRule(_localctx, 64, MemgraphCypher::RuleDumpQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    match(MemgraphCypher::DUMP);
    setState(667);
    match(MemgraphCypher::DATABASE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetReplicationRoleContext ------------------------------------------------------------------

MemgraphCypher::SetReplicationRoleContext::SetReplicationRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::REPLICATION() {
  return getToken(MemgraphCypher::REPLICATION, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::MAIN() {
  return getToken(MemgraphCypher::MAIN, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::REPLICA() {
  return getToken(MemgraphCypher::REPLICA, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

tree::TerminalNode* MemgraphCypher::SetReplicationRoleContext::PORT() {
  return getToken(MemgraphCypher::PORT, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::SetReplicationRoleContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::SetReplicationRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleSetReplicationRole;
}

void MemgraphCypher::SetReplicationRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetReplicationRole(this);
}

void MemgraphCypher::SetReplicationRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetReplicationRole(this);
}


antlrcpp::Any MemgraphCypher::SetReplicationRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSetReplicationRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetReplicationRoleContext* MemgraphCypher::setReplicationRole() {
  SetReplicationRoleContext *_localctx = _tracker.createInstance<SetReplicationRoleContext>(_ctx, getState());
  enterRule(_localctx, 66, MemgraphCypher::RuleSetReplicationRole);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(669);
    match(MemgraphCypher::SET);
    setState(670);
    match(MemgraphCypher::REPLICATION);
    setState(671);
    match(MemgraphCypher::ROLE);
    setState(672);
    match(MemgraphCypher::TO);
    setState(673);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::MAIN

    || _la == MemgraphCypher::REPLICA)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(677);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WITH) {
      setState(674);
      match(MemgraphCypher::WITH);
      setState(675);
      match(MemgraphCypher::PORT);
      setState(676);
      dynamic_cast<SetReplicationRoleContext *>(_localctx)->port = literal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowReplicationRoleContext ------------------------------------------------------------------

MemgraphCypher::ShowReplicationRoleContext::ShowReplicationRoleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowReplicationRoleContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowReplicationRoleContext::REPLICATION() {
  return getToken(MemgraphCypher::REPLICATION, 0);
}

tree::TerminalNode* MemgraphCypher::ShowReplicationRoleContext::ROLE() {
  return getToken(MemgraphCypher::ROLE, 0);
}


size_t MemgraphCypher::ShowReplicationRoleContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowReplicationRole;
}

void MemgraphCypher::ShowReplicationRoleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowReplicationRole(this);
}

void MemgraphCypher::ShowReplicationRoleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowReplicationRole(this);
}


antlrcpp::Any MemgraphCypher::ShowReplicationRoleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowReplicationRole(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowReplicationRoleContext* MemgraphCypher::showReplicationRole() {
  ShowReplicationRoleContext *_localctx = _tracker.createInstance<ShowReplicationRoleContext>(_ctx, getState());
  enterRule(_localctx, 68, MemgraphCypher::RuleShowReplicationRole);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    match(MemgraphCypher::SHOW);
    setState(680);
    match(MemgraphCypher::REPLICATION);
    setState(681);
    match(MemgraphCypher::ROLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReplicaNameContext ------------------------------------------------------------------

MemgraphCypher::ReplicaNameContext::ReplicaNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::ReplicaNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::ReplicaNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleReplicaName;
}

void MemgraphCypher::ReplicaNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReplicaName(this);
}

void MemgraphCypher::ReplicaNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReplicaName(this);
}


antlrcpp::Any MemgraphCypher::ReplicaNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReplicaName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReplicaNameContext* MemgraphCypher::replicaName() {
  ReplicaNameContext *_localctx = _tracker.createInstance<ReplicaNameContext>(_ctx, getState());
  enterRule(_localctx, 70, MemgraphCypher::RuleReplicaName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(683);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SocketAddressContext ------------------------------------------------------------------

MemgraphCypher::SocketAddressContext::SocketAddressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::SocketAddressContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::SocketAddressContext::getRuleIndex() const {
  return MemgraphCypher::RuleSocketAddress;
}

void MemgraphCypher::SocketAddressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSocketAddress(this);
}

void MemgraphCypher::SocketAddressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSocketAddress(this);
}


antlrcpp::Any MemgraphCypher::SocketAddressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSocketAddress(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SocketAddressContext* MemgraphCypher::socketAddress() {
  SocketAddressContext *_localctx = _tracker.createInstance<SocketAddressContext>(_ctx, getState());
  enterRule(_localctx, 72, MemgraphCypher::RuleSocketAddress);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(685);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegisterReplicaContext ------------------------------------------------------------------

MemgraphCypher::RegisterReplicaContext::RegisterReplicaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::REGISTER() {
  return getToken(MemgraphCypher::REGISTER, 0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::REPLICA() {
  return getToken(MemgraphCypher::REPLICA, 0);
}

MemgraphCypher::ReplicaNameContext* MemgraphCypher::RegisterReplicaContext::replicaName() {
  return getRuleContext<MemgraphCypher::ReplicaNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

MemgraphCypher::SocketAddressContext* MemgraphCypher::RegisterReplicaContext::socketAddress() {
  return getRuleContext<MemgraphCypher::SocketAddressContext>(0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::SYNC() {
  return getToken(MemgraphCypher::SYNC, 0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::ASYNC() {
  return getToken(MemgraphCypher::ASYNC, 0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

tree::TerminalNode* MemgraphCypher::RegisterReplicaContext::TIMEOUT() {
  return getToken(MemgraphCypher::TIMEOUT, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::RegisterReplicaContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::RegisterReplicaContext::getRuleIndex() const {
  return MemgraphCypher::RuleRegisterReplica;
}

void MemgraphCypher::RegisterReplicaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegisterReplica(this);
}

void MemgraphCypher::RegisterReplicaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegisterReplica(this);
}


antlrcpp::Any MemgraphCypher::RegisterReplicaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRegisterReplica(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RegisterReplicaContext* MemgraphCypher::registerReplica() {
  RegisterReplicaContext *_localctx = _tracker.createInstance<RegisterReplicaContext>(_ctx, getState());
  enterRule(_localctx, 74, MemgraphCypher::RuleRegisterReplica);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(687);
    match(MemgraphCypher::REGISTER);
    setState(688);
    match(MemgraphCypher::REPLICA);
    setState(689);
    replicaName();
    setState(690);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::ASYNC || _la == MemgraphCypher::SYNC)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(694);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WITH) {
      setState(691);
      match(MemgraphCypher::WITH);
      setState(692);
      match(MemgraphCypher::TIMEOUT);
      setState(693);
      dynamic_cast<RegisterReplicaContext *>(_localctx)->timeout = literal();
    }
    setState(696);
    match(MemgraphCypher::TO);
    setState(697);
    socketAddress();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropReplicaContext ------------------------------------------------------------------

MemgraphCypher::DropReplicaContext::DropReplicaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropReplicaContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropReplicaContext::REPLICA() {
  return getToken(MemgraphCypher::REPLICA, 0);
}

MemgraphCypher::ReplicaNameContext* MemgraphCypher::DropReplicaContext::replicaName() {
  return getRuleContext<MemgraphCypher::ReplicaNameContext>(0);
}


size_t MemgraphCypher::DropReplicaContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropReplica;
}

void MemgraphCypher::DropReplicaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropReplica(this);
}

void MemgraphCypher::DropReplicaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropReplica(this);
}


antlrcpp::Any MemgraphCypher::DropReplicaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropReplica(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropReplicaContext* MemgraphCypher::dropReplica() {
  DropReplicaContext *_localctx = _tracker.createInstance<DropReplicaContext>(_ctx, getState());
  enterRule(_localctx, 76, MemgraphCypher::RuleDropReplica);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(699);
    match(MemgraphCypher::DROP);
    setState(700);
    match(MemgraphCypher::REPLICA);
    setState(701);
    replicaName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowReplicasContext ------------------------------------------------------------------

MemgraphCypher::ShowReplicasContext::ShowReplicasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowReplicasContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowReplicasContext::REPLICAS() {
  return getToken(MemgraphCypher::REPLICAS, 0);
}


size_t MemgraphCypher::ShowReplicasContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowReplicas;
}

void MemgraphCypher::ShowReplicasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowReplicas(this);
}

void MemgraphCypher::ShowReplicasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowReplicas(this);
}


antlrcpp::Any MemgraphCypher::ShowReplicasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowReplicas(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowReplicasContext* MemgraphCypher::showReplicas() {
  ShowReplicasContext *_localctx = _tracker.createInstance<ShowReplicasContext>(_ctx, getState());
  enterRule(_localctx, 78, MemgraphCypher::RuleShowReplicas);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    match(MemgraphCypher::SHOW);
    setState(704);
    match(MemgraphCypher::REPLICAS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LockPathQueryContext ------------------------------------------------------------------

MemgraphCypher::LockPathQueryContext::LockPathQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::LockPathQueryContext::DATA() {
  return getToken(MemgraphCypher::DATA, 0);
}

tree::TerminalNode* MemgraphCypher::LockPathQueryContext::DIRECTORY() {
  return getToken(MemgraphCypher::DIRECTORY, 0);
}

tree::TerminalNode* MemgraphCypher::LockPathQueryContext::LOCK() {
  return getToken(MemgraphCypher::LOCK, 0);
}

tree::TerminalNode* MemgraphCypher::LockPathQueryContext::UNLOCK() {
  return getToken(MemgraphCypher::UNLOCK, 0);
}


size_t MemgraphCypher::LockPathQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleLockPathQuery;
}

void MemgraphCypher::LockPathQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLockPathQuery(this);
}

void MemgraphCypher::LockPathQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLockPathQuery(this);
}


antlrcpp::Any MemgraphCypher::LockPathQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLockPathQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LockPathQueryContext* MemgraphCypher::lockPathQuery() {
  LockPathQueryContext *_localctx = _tracker.createInstance<LockPathQueryContext>(_ctx, getState());
  enterRule(_localctx, 80, MemgraphCypher::RuleLockPathQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::LOCK

    || _la == MemgraphCypher::UNLOCK)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(707);
    match(MemgraphCypher::DATA);
    setState(708);
    match(MemgraphCypher::DIRECTORY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FreeMemoryQueryContext ------------------------------------------------------------------

MemgraphCypher::FreeMemoryQueryContext::FreeMemoryQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::FreeMemoryQueryContext::FREE() {
  return getToken(MemgraphCypher::FREE, 0);
}

tree::TerminalNode* MemgraphCypher::FreeMemoryQueryContext::MEMORY() {
  return getToken(MemgraphCypher::MEMORY, 0);
}


size_t MemgraphCypher::FreeMemoryQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleFreeMemoryQuery;
}

void MemgraphCypher::FreeMemoryQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFreeMemoryQuery(this);
}

void MemgraphCypher::FreeMemoryQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFreeMemoryQuery(this);
}


antlrcpp::Any MemgraphCypher::FreeMemoryQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitFreeMemoryQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::FreeMemoryQueryContext* MemgraphCypher::freeMemoryQuery() {
  FreeMemoryQueryContext *_localctx = _tracker.createInstance<FreeMemoryQueryContext>(_ctx, getState());
  enterRule(_localctx, 82, MemgraphCypher::RuleFreeMemoryQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    match(MemgraphCypher::FREE);
    setState(711);
    match(MemgraphCypher::MEMORY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriggerNameContext ------------------------------------------------------------------

MemgraphCypher::TriggerNameContext::TriggerNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::TriggerNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::TriggerNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleTriggerName;
}

void MemgraphCypher::TriggerNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerName(this);
}

void MemgraphCypher::TriggerNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerName(this);
}


antlrcpp::Any MemgraphCypher::TriggerNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitTriggerName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::TriggerNameContext* MemgraphCypher::triggerName() {
  TriggerNameContext *_localctx = _tracker.createInstance<TriggerNameContext>(_ctx, getState());
  enterRule(_localctx, 84, MemgraphCypher::RuleTriggerName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(713);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriggerStatementContext ------------------------------------------------------------------

MemgraphCypher::TriggerStatementContext::TriggerStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MemgraphCypher::TriggerStatementContext::getRuleIndex() const {
  return MemgraphCypher::RuleTriggerStatement;
}

void MemgraphCypher::TriggerStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriggerStatement(this);
}

void MemgraphCypher::TriggerStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriggerStatement(this);
}


antlrcpp::Any MemgraphCypher::TriggerStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitTriggerStatement(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::TriggerStatementContext* MemgraphCypher::triggerStatement() {
  TriggerStatementContext *_localctx = _tracker.createInstance<TriggerStatementContext>(_ctx, getState());
  enterRule(_localctx, 86, MemgraphCypher::RuleTriggerStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(718);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(715);
        matchWildcard(); 
      }
      setState(720);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyVertexContext ------------------------------------------------------------------

MemgraphCypher::EmptyVertexContext::EmptyVertexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::EmptyVertexContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::EmptyVertexContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}


size_t MemgraphCypher::EmptyVertexContext::getRuleIndex() const {
  return MemgraphCypher::RuleEmptyVertex;
}

void MemgraphCypher::EmptyVertexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyVertex(this);
}

void MemgraphCypher::EmptyVertexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyVertex(this);
}


antlrcpp::Any MemgraphCypher::EmptyVertexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitEmptyVertex(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::EmptyVertexContext* MemgraphCypher::emptyVertex() {
  EmptyVertexContext *_localctx = _tracker.createInstance<EmptyVertexContext>(_ctx, getState());
  enterRule(_localctx, 88, MemgraphCypher::RuleEmptyVertex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(721);
    match(MemgraphCypher::LPAREN);
    setState(722);
    match(MemgraphCypher::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyEdgeContext ------------------------------------------------------------------

MemgraphCypher::EmptyEdgeContext::EmptyEdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::DashContext *> MemgraphCypher::EmptyEdgeContext::dash() {
  return getRuleContexts<MemgraphCypher::DashContext>();
}

MemgraphCypher::DashContext* MemgraphCypher::EmptyEdgeContext::dash(size_t i) {
  return getRuleContext<MemgraphCypher::DashContext>(i);
}

MemgraphCypher::RightArrowHeadContext* MemgraphCypher::EmptyEdgeContext::rightArrowHead() {
  return getRuleContext<MemgraphCypher::RightArrowHeadContext>(0);
}


size_t MemgraphCypher::EmptyEdgeContext::getRuleIndex() const {
  return MemgraphCypher::RuleEmptyEdge;
}

void MemgraphCypher::EmptyEdgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyEdge(this);
}

void MemgraphCypher::EmptyEdgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyEdge(this);
}


antlrcpp::Any MemgraphCypher::EmptyEdgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitEmptyEdge(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::EmptyEdgeContext* MemgraphCypher::emptyEdge() {
  EmptyEdgeContext *_localctx = _tracker.createInstance<EmptyEdgeContext>(_ctx, getState());
  enterRule(_localctx, 90, MemgraphCypher::RuleEmptyEdge);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(724);
    dash();
    setState(725);
    dash();
    setState(726);
    rightArrowHead();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateTriggerContext ------------------------------------------------------------------

MemgraphCypher::CreateTriggerContext::CreateTriggerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MemgraphCypher::CreateTriggerContext::CREATE() {
  return getTokens(MemgraphCypher::CREATE);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::CREATE(size_t i) {
  return getToken(MemgraphCypher::CREATE, i);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::TRIGGER() {
  return getToken(MemgraphCypher::TRIGGER, 0);
}

MemgraphCypher::TriggerNameContext* MemgraphCypher::CreateTriggerContext::triggerName() {
  return getRuleContext<MemgraphCypher::TriggerNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::COMMIT() {
  return getToken(MemgraphCypher::COMMIT, 0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::EXECUTE() {
  return getToken(MemgraphCypher::EXECUTE, 0);
}

MemgraphCypher::TriggerStatementContext* MemgraphCypher::CreateTriggerContext::triggerStatement() {
  return getRuleContext<MemgraphCypher::TriggerStatementContext>(0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::AFTER() {
  return getToken(MemgraphCypher::AFTER, 0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::BEFORE() {
  return getToken(MemgraphCypher::BEFORE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::UPDATE() {
  return getToken(MemgraphCypher::UPDATE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateTriggerContext::DELETE() {
  return getToken(MemgraphCypher::DELETE, 0);
}

MemgraphCypher::EmptyVertexContext* MemgraphCypher::CreateTriggerContext::emptyVertex() {
  return getRuleContext<MemgraphCypher::EmptyVertexContext>(0);
}

MemgraphCypher::EmptyEdgeContext* MemgraphCypher::CreateTriggerContext::emptyEdge() {
  return getRuleContext<MemgraphCypher::EmptyEdgeContext>(0);
}


size_t MemgraphCypher::CreateTriggerContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateTrigger;
}

void MemgraphCypher::CreateTriggerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateTrigger(this);
}

void MemgraphCypher::CreateTriggerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateTrigger(this);
}


antlrcpp::Any MemgraphCypher::CreateTriggerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateTrigger(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateTriggerContext* MemgraphCypher::createTrigger() {
  CreateTriggerContext *_localctx = _tracker.createInstance<CreateTriggerContext>(_ctx, getState());
  enterRule(_localctx, 92, MemgraphCypher::RuleCreateTrigger);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(728);
    match(MemgraphCypher::CREATE);
    setState(729);
    match(MemgraphCypher::TRIGGER);
    setState(730);
    triggerName();
    setState(737);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::ON) {
      setState(731);
      match(MemgraphCypher::ON);
      setState(734);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MemgraphCypher::LPAREN: {
          setState(732);
          emptyVertex();
          break;
        }

        case MemgraphCypher::MINUS:
        case MemgraphCypher::DashPart: {
          setState(733);
          emptyEdge();
          break;
        }

        case MemgraphCypher::UPDATE:
        case MemgraphCypher::CREATE:
        case MemgraphCypher::DELETE: {
          break;
        }

      default:
        break;
      }
      setState(736);
      _la = _input->LA(1);
      if (!(((((_la - 85) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 85)) & ((1ULL << (MemgraphCypher::UPDATE - 85))
        | (1ULL << (MemgraphCypher::CREATE - 85))
        | (1ULL << (MemgraphCypher::DELETE - 85)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(739);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::AFTER

    || _la == MemgraphCypher::BEFORE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(740);
    match(MemgraphCypher::COMMIT);
    setState(741);
    match(MemgraphCypher::EXECUTE);
    setState(742);
    triggerStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropTriggerContext ------------------------------------------------------------------

MemgraphCypher::DropTriggerContext::DropTriggerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropTriggerContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropTriggerContext::TRIGGER() {
  return getToken(MemgraphCypher::TRIGGER, 0);
}

MemgraphCypher::TriggerNameContext* MemgraphCypher::DropTriggerContext::triggerName() {
  return getRuleContext<MemgraphCypher::TriggerNameContext>(0);
}


size_t MemgraphCypher::DropTriggerContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropTrigger;
}

void MemgraphCypher::DropTriggerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropTrigger(this);
}

void MemgraphCypher::DropTriggerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropTrigger(this);
}


antlrcpp::Any MemgraphCypher::DropTriggerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropTrigger(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropTriggerContext* MemgraphCypher::dropTrigger() {
  DropTriggerContext *_localctx = _tracker.createInstance<DropTriggerContext>(_ctx, getState());
  enterRule(_localctx, 94, MemgraphCypher::RuleDropTrigger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(744);
    match(MemgraphCypher::DROP);
    setState(745);
    match(MemgraphCypher::TRIGGER);
    setState(746);
    triggerName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowTriggersContext ------------------------------------------------------------------

MemgraphCypher::ShowTriggersContext::ShowTriggersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowTriggersContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowTriggersContext::TRIGGERS() {
  return getToken(MemgraphCypher::TRIGGERS, 0);
}


size_t MemgraphCypher::ShowTriggersContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowTriggers;
}

void MemgraphCypher::ShowTriggersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowTriggers(this);
}

void MemgraphCypher::ShowTriggersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowTriggers(this);
}


antlrcpp::Any MemgraphCypher::ShowTriggersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowTriggers(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowTriggersContext* MemgraphCypher::showTriggers() {
  ShowTriggersContext *_localctx = _tracker.createInstance<ShowTriggersContext>(_ctx, getState());
  enterRule(_localctx, 96, MemgraphCypher::RuleShowTriggers);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(748);
    match(MemgraphCypher::SHOW);
    setState(749);
    match(MemgraphCypher::TRIGGERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IsolationLevelContext ------------------------------------------------------------------

MemgraphCypher::IsolationLevelContext::IsolationLevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::IsolationLevelContext::SNAPSHOT() {
  return getToken(MemgraphCypher::SNAPSHOT, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelContext::ISOLATION() {
  return getToken(MemgraphCypher::ISOLATION, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelContext::READ() {
  return getToken(MemgraphCypher::READ, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelContext::COMMITTED() {
  return getToken(MemgraphCypher::COMMITTED, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelContext::UNCOMMITTED() {
  return getToken(MemgraphCypher::UNCOMMITTED, 0);
}


size_t MemgraphCypher::IsolationLevelContext::getRuleIndex() const {
  return MemgraphCypher::RuleIsolationLevel;
}

void MemgraphCypher::IsolationLevelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsolationLevel(this);
}

void MemgraphCypher::IsolationLevelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsolationLevel(this);
}


antlrcpp::Any MemgraphCypher::IsolationLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIsolationLevel(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IsolationLevelContext* MemgraphCypher::isolationLevel() {
  IsolationLevelContext *_localctx = _tracker.createInstance<IsolationLevelContext>(_ctx, getState());
  enterRule(_localctx, 98, MemgraphCypher::RuleIsolationLevel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(757);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(751);
      match(MemgraphCypher::SNAPSHOT);
      setState(752);
      match(MemgraphCypher::ISOLATION);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(753);
      match(MemgraphCypher::READ);
      setState(754);
      match(MemgraphCypher::COMMITTED);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(755);
      match(MemgraphCypher::READ);
      setState(756);
      match(MemgraphCypher::UNCOMMITTED);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IsolationLevelScopeContext ------------------------------------------------------------------

MemgraphCypher::IsolationLevelScopeContext::IsolationLevelScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::IsolationLevelScopeContext::GLOBAL() {
  return getToken(MemgraphCypher::GLOBAL, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelScopeContext::SESSION() {
  return getToken(MemgraphCypher::SESSION, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelScopeContext::NEXT() {
  return getToken(MemgraphCypher::NEXT, 0);
}


size_t MemgraphCypher::IsolationLevelScopeContext::getRuleIndex() const {
  return MemgraphCypher::RuleIsolationLevelScope;
}

void MemgraphCypher::IsolationLevelScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsolationLevelScope(this);
}

void MemgraphCypher::IsolationLevelScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsolationLevelScope(this);
}


antlrcpp::Any MemgraphCypher::IsolationLevelScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIsolationLevelScope(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IsolationLevelScopeContext* MemgraphCypher::isolationLevelScope() {
  IsolationLevelScopeContext *_localctx = _tracker.createInstance<IsolationLevelScopeContext>(_ctx, getState());
  enterRule(_localctx, 100, MemgraphCypher::RuleIsolationLevelScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(759);
    _la = _input->LA(1);
    if (!(((((_la - 34) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 34)) & ((1ULL << (MemgraphCypher::GLOBAL - 34))
      | (1ULL << (MemgraphCypher::NEXT - 34))
      | (1ULL << (MemgraphCypher::SESSION - 34)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IsolationLevelQueryContext ------------------------------------------------------------------

MemgraphCypher::IsolationLevelQueryContext::IsolationLevelQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::IsolationLevelQueryContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

MemgraphCypher::IsolationLevelScopeContext* MemgraphCypher::IsolationLevelQueryContext::isolationLevelScope() {
  return getRuleContext<MemgraphCypher::IsolationLevelScopeContext>(0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelQueryContext::TRANSACTION() {
  return getToken(MemgraphCypher::TRANSACTION, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelQueryContext::ISOLATION() {
  return getToken(MemgraphCypher::ISOLATION, 0);
}

tree::TerminalNode* MemgraphCypher::IsolationLevelQueryContext::LEVEL() {
  return getToken(MemgraphCypher::LEVEL, 0);
}

MemgraphCypher::IsolationLevelContext* MemgraphCypher::IsolationLevelQueryContext::isolationLevel() {
  return getRuleContext<MemgraphCypher::IsolationLevelContext>(0);
}


size_t MemgraphCypher::IsolationLevelQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleIsolationLevelQuery;
}

void MemgraphCypher::IsolationLevelQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsolationLevelQuery(this);
}

void MemgraphCypher::IsolationLevelQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsolationLevelQuery(this);
}


antlrcpp::Any MemgraphCypher::IsolationLevelQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIsolationLevelQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IsolationLevelQueryContext* MemgraphCypher::isolationLevelQuery() {
  IsolationLevelQueryContext *_localctx = _tracker.createInstance<IsolationLevelQueryContext>(_ctx, getState());
  enterRule(_localctx, 102, MemgraphCypher::RuleIsolationLevelQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(761);
    match(MemgraphCypher::SET);
    setState(762);
    isolationLevelScope();
    setState(763);
    match(MemgraphCypher::TRANSACTION);
    setState(764);
    match(MemgraphCypher::ISOLATION);
    setState(765);
    match(MemgraphCypher::LEVEL);
    setState(766);
    isolationLevel();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateSnapshotQueryContext ------------------------------------------------------------------

MemgraphCypher::CreateSnapshotQueryContext::CreateSnapshotQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CreateSnapshotQueryContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateSnapshotQueryContext::SNAPSHOT() {
  return getToken(MemgraphCypher::SNAPSHOT, 0);
}


size_t MemgraphCypher::CreateSnapshotQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateSnapshotQuery;
}

void MemgraphCypher::CreateSnapshotQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateSnapshotQuery(this);
}

void MemgraphCypher::CreateSnapshotQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateSnapshotQuery(this);
}


antlrcpp::Any MemgraphCypher::CreateSnapshotQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateSnapshotQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateSnapshotQueryContext* MemgraphCypher::createSnapshotQuery() {
  CreateSnapshotQueryContext *_localctx = _tracker.createInstance<CreateSnapshotQueryContext>(_ctx, getState());
  enterRule(_localctx, 104, MemgraphCypher::RuleCreateSnapshotQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(768);
    match(MemgraphCypher::CREATE);
    setState(769);
    match(MemgraphCypher::SNAPSHOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StreamNameContext ------------------------------------------------------------------

MemgraphCypher::StreamNameContext::StreamNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::StreamNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::StreamNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleStreamName;
}

void MemgraphCypher::StreamNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStreamName(this);
}

void MemgraphCypher::StreamNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStreamName(this);
}


antlrcpp::Any MemgraphCypher::StreamNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStreamName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::streamName() {
  StreamNameContext *_localctx = _tracker.createInstance<StreamNameContext>(_ctx, getState());
  enterRule(_localctx, 106, MemgraphCypher::RuleStreamName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(771);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolicNameWithMinusContext ------------------------------------------------------------------

MemgraphCypher::SymbolicNameWithMinusContext::SymbolicNameWithMinusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::SymbolicNameContext *> MemgraphCypher::SymbolicNameWithMinusContext::symbolicName() {
  return getRuleContexts<MemgraphCypher::SymbolicNameContext>();
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::SymbolicNameWithMinusContext::symbolicName(size_t i) {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::SymbolicNameWithMinusContext::MINUS() {
  return getTokens(MemgraphCypher::MINUS);
}

tree::TerminalNode* MemgraphCypher::SymbolicNameWithMinusContext::MINUS(size_t i) {
  return getToken(MemgraphCypher::MINUS, i);
}


size_t MemgraphCypher::SymbolicNameWithMinusContext::getRuleIndex() const {
  return MemgraphCypher::RuleSymbolicNameWithMinus;
}

void MemgraphCypher::SymbolicNameWithMinusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbolicNameWithMinus(this);
}

void MemgraphCypher::SymbolicNameWithMinusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbolicNameWithMinus(this);
}


antlrcpp::Any MemgraphCypher::SymbolicNameWithMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSymbolicNameWithMinus(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SymbolicNameWithMinusContext* MemgraphCypher::symbolicNameWithMinus() {
  SymbolicNameWithMinusContext *_localctx = _tracker.createInstance<SymbolicNameWithMinusContext>(_ctx, getState());
  enterRule(_localctx, 108, MemgraphCypher::RuleSymbolicNameWithMinus);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(773);
    symbolicName();
    setState(778);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::MINUS) {
      setState(774);
      match(MemgraphCypher::MINUS);
      setState(775);
      symbolicName();
      setState(780);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolicNameWithDotsAndMinusContext ------------------------------------------------------------------

MemgraphCypher::SymbolicNameWithDotsAndMinusContext::SymbolicNameWithDotsAndMinusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::SymbolicNameWithMinusContext *> MemgraphCypher::SymbolicNameWithDotsAndMinusContext::symbolicNameWithMinus() {
  return getRuleContexts<MemgraphCypher::SymbolicNameWithMinusContext>();
}

MemgraphCypher::SymbolicNameWithMinusContext* MemgraphCypher::SymbolicNameWithDotsAndMinusContext::symbolicNameWithMinus(size_t i) {
  return getRuleContext<MemgraphCypher::SymbolicNameWithMinusContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::SymbolicNameWithDotsAndMinusContext::DOT() {
  return getTokens(MemgraphCypher::DOT);
}

tree::TerminalNode* MemgraphCypher::SymbolicNameWithDotsAndMinusContext::DOT(size_t i) {
  return getToken(MemgraphCypher::DOT, i);
}


size_t MemgraphCypher::SymbolicNameWithDotsAndMinusContext::getRuleIndex() const {
  return MemgraphCypher::RuleSymbolicNameWithDotsAndMinus;
}

void MemgraphCypher::SymbolicNameWithDotsAndMinusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbolicNameWithDotsAndMinus(this);
}

void MemgraphCypher::SymbolicNameWithDotsAndMinusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbolicNameWithDotsAndMinus(this);
}


antlrcpp::Any MemgraphCypher::SymbolicNameWithDotsAndMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSymbolicNameWithDotsAndMinus(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SymbolicNameWithDotsAndMinusContext* MemgraphCypher::symbolicNameWithDotsAndMinus() {
  SymbolicNameWithDotsAndMinusContext *_localctx = _tracker.createInstance<SymbolicNameWithDotsAndMinusContext>(_ctx, getState());
  enterRule(_localctx, 110, MemgraphCypher::RuleSymbolicNameWithDotsAndMinus);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(781);
    symbolicNameWithMinus();
    setState(786);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::DOT) {
      setState(782);
      match(MemgraphCypher::DOT);
      setState(783);
      symbolicNameWithMinus();
      setState(788);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolicTopicNamesContext ------------------------------------------------------------------

MemgraphCypher::SymbolicTopicNamesContext::SymbolicTopicNamesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::SymbolicNameWithDotsAndMinusContext *> MemgraphCypher::SymbolicTopicNamesContext::symbolicNameWithDotsAndMinus() {
  return getRuleContexts<MemgraphCypher::SymbolicNameWithDotsAndMinusContext>();
}

MemgraphCypher::SymbolicNameWithDotsAndMinusContext* MemgraphCypher::SymbolicTopicNamesContext::symbolicNameWithDotsAndMinus(size_t i) {
  return getRuleContext<MemgraphCypher::SymbolicNameWithDotsAndMinusContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::SymbolicTopicNamesContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::SymbolicTopicNamesContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::SymbolicTopicNamesContext::getRuleIndex() const {
  return MemgraphCypher::RuleSymbolicTopicNames;
}

void MemgraphCypher::SymbolicTopicNamesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbolicTopicNames(this);
}

void MemgraphCypher::SymbolicTopicNamesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbolicTopicNames(this);
}


antlrcpp::Any MemgraphCypher::SymbolicTopicNamesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSymbolicTopicNames(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SymbolicTopicNamesContext* MemgraphCypher::symbolicTopicNames() {
  SymbolicTopicNamesContext *_localctx = _tracker.createInstance<SymbolicTopicNamesContext>(_ctx, getState());
  enterRule(_localctx, 112, MemgraphCypher::RuleSymbolicTopicNames);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(789);
    symbolicNameWithDotsAndMinus();
    setState(794);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(790);
      match(MemgraphCypher::COMMA);
      setState(791);
      symbolicNameWithDotsAndMinus();
      setState(796);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopicNamesContext ------------------------------------------------------------------

MemgraphCypher::TopicNamesContext::TopicNamesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicTopicNamesContext* MemgraphCypher::TopicNamesContext::symbolicTopicNames() {
  return getRuleContext<MemgraphCypher::SymbolicTopicNamesContext>(0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::TopicNamesContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::TopicNamesContext::getRuleIndex() const {
  return MemgraphCypher::RuleTopicNames;
}

void MemgraphCypher::TopicNamesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopicNames(this);
}

void MemgraphCypher::TopicNamesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopicNames(this);
}


antlrcpp::Any MemgraphCypher::TopicNamesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitTopicNames(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::TopicNamesContext* MemgraphCypher::topicNames() {
  TopicNamesContext *_localctx = _tracker.createInstance<TopicNamesContext>(_ctx, getState());
  enterRule(_localctx, 114, MemgraphCypher::RuleTopicNames);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(799);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(797);
      symbolicTopicNames();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(798);
      literal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonCreateStreamConfigContext ------------------------------------------------------------------

MemgraphCypher::CommonCreateStreamConfigContext::CommonCreateStreamConfigContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CommonCreateStreamConfigContext::TRANSFORM() {
  return getToken(MemgraphCypher::TRANSFORM, 0);
}

MemgraphCypher::ProcedureNameContext* MemgraphCypher::CommonCreateStreamConfigContext::procedureName() {
  return getRuleContext<MemgraphCypher::ProcedureNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CommonCreateStreamConfigContext::BATCH_INTERVAL() {
  return getToken(MemgraphCypher::BATCH_INTERVAL, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::CommonCreateStreamConfigContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}

tree::TerminalNode* MemgraphCypher::CommonCreateStreamConfigContext::BATCH_SIZE() {
  return getToken(MemgraphCypher::BATCH_SIZE, 0);
}


size_t MemgraphCypher::CommonCreateStreamConfigContext::getRuleIndex() const {
  return MemgraphCypher::RuleCommonCreateStreamConfig;
}

void MemgraphCypher::CommonCreateStreamConfigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommonCreateStreamConfig(this);
}

void MemgraphCypher::CommonCreateStreamConfigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommonCreateStreamConfig(this);
}


antlrcpp::Any MemgraphCypher::CommonCreateStreamConfigContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCommonCreateStreamConfig(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CommonCreateStreamConfigContext* MemgraphCypher::commonCreateStreamConfig() {
  CommonCreateStreamConfigContext *_localctx = _tracker.createInstance<CommonCreateStreamConfigContext>(_ctx, getState());
  enterRule(_localctx, 116, MemgraphCypher::RuleCommonCreateStreamConfig);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(807);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::TRANSFORM: {
        enterOuterAlt(_localctx, 1);
        setState(801);
        match(MemgraphCypher::TRANSFORM);
        setState(802);
        dynamic_cast<CommonCreateStreamConfigContext *>(_localctx)->transformationName = procedureName();
        break;
      }

      case MemgraphCypher::BATCH_INTERVAL: {
        enterOuterAlt(_localctx, 2);
        setState(803);
        match(MemgraphCypher::BATCH_INTERVAL);
        setState(804);
        dynamic_cast<CommonCreateStreamConfigContext *>(_localctx)->batchInterval = literal();
        break;
      }

      case MemgraphCypher::BATCH_SIZE: {
        enterOuterAlt(_localctx, 3);
        setState(805);
        match(MemgraphCypher::BATCH_SIZE);
        setState(806);
        dynamic_cast<CommonCreateStreamConfigContext *>(_localctx)->batchSize = literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateStreamContext ------------------------------------------------------------------

MemgraphCypher::CreateStreamContext::CreateStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::KafkaCreateStreamContext* MemgraphCypher::CreateStreamContext::kafkaCreateStream() {
  return getRuleContext<MemgraphCypher::KafkaCreateStreamContext>(0);
}

MemgraphCypher::PulsarCreateStreamContext* MemgraphCypher::CreateStreamContext::pulsarCreateStream() {
  return getRuleContext<MemgraphCypher::PulsarCreateStreamContext>(0);
}


size_t MemgraphCypher::CreateStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateStream;
}

void MemgraphCypher::CreateStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateStream(this);
}

void MemgraphCypher::CreateStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateStream(this);
}


antlrcpp::Any MemgraphCypher::CreateStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateStreamContext* MemgraphCypher::createStream() {
  CreateStreamContext *_localctx = _tracker.createInstance<CreateStreamContext>(_ctx, getState());
  enterRule(_localctx, 118, MemgraphCypher::RuleCreateStream);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(811);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(809);
      kafkaCreateStream();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(810);
      pulsarCreateStream();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigKeyValuePairContext ------------------------------------------------------------------

MemgraphCypher::ConfigKeyValuePairContext::ConfigKeyValuePairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::LiteralContext *> MemgraphCypher::ConfigKeyValuePairContext::literal() {
  return getRuleContexts<MemgraphCypher::LiteralContext>();
}

MemgraphCypher::LiteralContext* MemgraphCypher::ConfigKeyValuePairContext::literal(size_t i) {
  return getRuleContext<MemgraphCypher::LiteralContext>(i);
}

tree::TerminalNode* MemgraphCypher::ConfigKeyValuePairContext::COLON() {
  return getToken(MemgraphCypher::COLON, 0);
}


size_t MemgraphCypher::ConfigKeyValuePairContext::getRuleIndex() const {
  return MemgraphCypher::RuleConfigKeyValuePair;
}

void MemgraphCypher::ConfigKeyValuePairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigKeyValuePair(this);
}

void MemgraphCypher::ConfigKeyValuePairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigKeyValuePair(this);
}


antlrcpp::Any MemgraphCypher::ConfigKeyValuePairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConfigKeyValuePair(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConfigKeyValuePairContext* MemgraphCypher::configKeyValuePair() {
  ConfigKeyValuePairContext *_localctx = _tracker.createInstance<ConfigKeyValuePairContext>(_ctx, getState());
  enterRule(_localctx, 120, MemgraphCypher::RuleConfigKeyValuePair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(813);
    literal();
    setState(814);
    match(MemgraphCypher::COLON);
    setState(815);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigMapContext ------------------------------------------------------------------

MemgraphCypher::ConfigMapContext::ConfigMapContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ConfigMapContext::LBRACE() {
  return getToken(MemgraphCypher::LBRACE, 0);
}

tree::TerminalNode* MemgraphCypher::ConfigMapContext::RBRACE() {
  return getToken(MemgraphCypher::RBRACE, 0);
}

std::vector<MemgraphCypher::ConfigKeyValuePairContext *> MemgraphCypher::ConfigMapContext::configKeyValuePair() {
  return getRuleContexts<MemgraphCypher::ConfigKeyValuePairContext>();
}

MemgraphCypher::ConfigKeyValuePairContext* MemgraphCypher::ConfigMapContext::configKeyValuePair(size_t i) {
  return getRuleContext<MemgraphCypher::ConfigKeyValuePairContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ConfigMapContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::ConfigMapContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::ConfigMapContext::getRuleIndex() const {
  return MemgraphCypher::RuleConfigMap;
}

void MemgraphCypher::ConfigMapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigMap(this);
}

void MemgraphCypher::ConfigMapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigMap(this);
}


antlrcpp::Any MemgraphCypher::ConfigMapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConfigMap(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConfigMapContext* MemgraphCypher::configMap() {
  ConfigMapContext *_localctx = _tracker.createInstance<ConfigMapContext>(_ctx, getState());
  enterRule(_localctx, 122, MemgraphCypher::RuleConfigMap);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(817);
    match(MemgraphCypher::LBRACE);
    setState(826);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 93) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 93)) & ((1ULL << (MemgraphCypher::LBRACK - 93))
      | (1ULL << (MemgraphCypher::LBRACE - 93))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 93))
      | (1ULL << (MemgraphCypher::FALSE - 93)))) != 0) || ((((_la - 183) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 183)) & ((1ULL << (MemgraphCypher::TRUE - 183))
      | (1ULL << (MemgraphCypher::StringLiteral - 183))
      | (1ULL << (MemgraphCypher::DecimalLiteral - 183))
      | (1ULL << (MemgraphCypher::OctalLiteral - 183))
      | (1ULL << (MemgraphCypher::HexadecimalLiteral - 183))
      | (1ULL << (MemgraphCypher::FloatingLiteral - 183)))) != 0)) {
      setState(818);
      configKeyValuePair();
      setState(823);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(819);
        match(MemgraphCypher::COMMA);
        setState(820);
        configKeyValuePair();
        setState(825);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(828);
    match(MemgraphCypher::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KafkaCreateStreamConfigContext ------------------------------------------------------------------

MemgraphCypher::KafkaCreateStreamConfigContext::KafkaCreateStreamConfigContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamConfigContext::TOPICS() {
  return getToken(MemgraphCypher::TOPICS, 0);
}

MemgraphCypher::TopicNamesContext* MemgraphCypher::KafkaCreateStreamConfigContext::topicNames() {
  return getRuleContext<MemgraphCypher::TopicNamesContext>(0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamConfigContext::CONSUMER_GROUP() {
  return getToken(MemgraphCypher::CONSUMER_GROUP, 0);
}

MemgraphCypher::SymbolicNameWithDotsAndMinusContext* MemgraphCypher::KafkaCreateStreamConfigContext::symbolicNameWithDotsAndMinus() {
  return getRuleContext<MemgraphCypher::SymbolicNameWithDotsAndMinusContext>(0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamConfigContext::BOOTSTRAP_SERVERS() {
  return getToken(MemgraphCypher::BOOTSTRAP_SERVERS, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::KafkaCreateStreamConfigContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamConfigContext::CONFIGS() {
  return getToken(MemgraphCypher::CONFIGS, 0);
}

MemgraphCypher::ConfigMapContext* MemgraphCypher::KafkaCreateStreamConfigContext::configMap() {
  return getRuleContext<MemgraphCypher::ConfigMapContext>(0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamConfigContext::CREDENTIALS() {
  return getToken(MemgraphCypher::CREDENTIALS, 0);
}

MemgraphCypher::CommonCreateStreamConfigContext* MemgraphCypher::KafkaCreateStreamConfigContext::commonCreateStreamConfig() {
  return getRuleContext<MemgraphCypher::CommonCreateStreamConfigContext>(0);
}


size_t MemgraphCypher::KafkaCreateStreamConfigContext::getRuleIndex() const {
  return MemgraphCypher::RuleKafkaCreateStreamConfig;
}

void MemgraphCypher::KafkaCreateStreamConfigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKafkaCreateStreamConfig(this);
}

void MemgraphCypher::KafkaCreateStreamConfigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKafkaCreateStreamConfig(this);
}


antlrcpp::Any MemgraphCypher::KafkaCreateStreamConfigContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitKafkaCreateStreamConfig(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::KafkaCreateStreamConfigContext* MemgraphCypher::kafkaCreateStreamConfig() {
  KafkaCreateStreamConfigContext *_localctx = _tracker.createInstance<KafkaCreateStreamConfigContext>(_ctx, getState());
  enterRule(_localctx, 124, MemgraphCypher::RuleKafkaCreateStreamConfig);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(841);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::TOPICS: {
        enterOuterAlt(_localctx, 1);
        setState(830);
        match(MemgraphCypher::TOPICS);
        setState(831);
        topicNames();
        break;
      }

      case MemgraphCypher::CONSUMER_GROUP: {
        enterOuterAlt(_localctx, 2);
        setState(832);
        match(MemgraphCypher::CONSUMER_GROUP);
        setState(833);
        dynamic_cast<KafkaCreateStreamConfigContext *>(_localctx)->consumerGroup = symbolicNameWithDotsAndMinus();
        break;
      }

      case MemgraphCypher::BOOTSTRAP_SERVERS: {
        enterOuterAlt(_localctx, 3);
        setState(834);
        match(MemgraphCypher::BOOTSTRAP_SERVERS);
        setState(835);
        dynamic_cast<KafkaCreateStreamConfigContext *>(_localctx)->bootstrapServers = literal();
        break;
      }

      case MemgraphCypher::CONFIGS: {
        enterOuterAlt(_localctx, 4);
        setState(836);
        match(MemgraphCypher::CONFIGS);
        setState(837);
        dynamic_cast<KafkaCreateStreamConfigContext *>(_localctx)->configsMap = configMap();
        break;
      }

      case MemgraphCypher::CREDENTIALS: {
        enterOuterAlt(_localctx, 5);
        setState(838);
        match(MemgraphCypher::CREDENTIALS);
        setState(839);
        dynamic_cast<KafkaCreateStreamConfigContext *>(_localctx)->credentialsMap = configMap();
        break;
      }

      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::TRANSFORM: {
        enterOuterAlt(_localctx, 6);
        setState(840);
        commonCreateStreamConfig();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KafkaCreateStreamContext ------------------------------------------------------------------

MemgraphCypher::KafkaCreateStreamContext::KafkaCreateStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamContext::KAFKA() {
  return getToken(MemgraphCypher::KAFKA, 0);
}

tree::TerminalNode* MemgraphCypher::KafkaCreateStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::KafkaCreateStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}

std::vector<MemgraphCypher::KafkaCreateStreamConfigContext *> MemgraphCypher::KafkaCreateStreamContext::kafkaCreateStreamConfig() {
  return getRuleContexts<MemgraphCypher::KafkaCreateStreamConfigContext>();
}

MemgraphCypher::KafkaCreateStreamConfigContext* MemgraphCypher::KafkaCreateStreamContext::kafkaCreateStreamConfig(size_t i) {
  return getRuleContext<MemgraphCypher::KafkaCreateStreamConfigContext>(i);
}


size_t MemgraphCypher::KafkaCreateStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleKafkaCreateStream;
}

void MemgraphCypher::KafkaCreateStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKafkaCreateStream(this);
}

void MemgraphCypher::KafkaCreateStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKafkaCreateStream(this);
}


antlrcpp::Any MemgraphCypher::KafkaCreateStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitKafkaCreateStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::KafkaCreateStreamContext* MemgraphCypher::kafkaCreateStream() {
  KafkaCreateStreamContext *_localctx = _tracker.createInstance<KafkaCreateStreamContext>(_ctx, getState());
  enterRule(_localctx, 126, MemgraphCypher::RuleKafkaCreateStream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(843);
    match(MemgraphCypher::CREATE);
    setState(844);
    match(MemgraphCypher::KAFKA);
    setState(845);
    match(MemgraphCypher::STREAM);
    setState(846);
    streamName();
    setState(850);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS))) != 0) || _la == MemgraphCypher::TOPICS

    || _la == MemgraphCypher::TRANSFORM) {
      setState(847);
      kafkaCreateStreamConfig();
      setState(852);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PulsarCreateStreamConfigContext ------------------------------------------------------------------

MemgraphCypher::PulsarCreateStreamConfigContext::PulsarCreateStreamConfigContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PulsarCreateStreamConfigContext::TOPICS() {
  return getToken(MemgraphCypher::TOPICS, 0);
}

MemgraphCypher::TopicNamesContext* MemgraphCypher::PulsarCreateStreamConfigContext::topicNames() {
  return getRuleContext<MemgraphCypher::TopicNamesContext>(0);
}

tree::TerminalNode* MemgraphCypher::PulsarCreateStreamConfigContext::SERVICE_URL() {
  return getToken(MemgraphCypher::SERVICE_URL, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::PulsarCreateStreamConfigContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}

MemgraphCypher::CommonCreateStreamConfigContext* MemgraphCypher::PulsarCreateStreamConfigContext::commonCreateStreamConfig() {
  return getRuleContext<MemgraphCypher::CommonCreateStreamConfigContext>(0);
}


size_t MemgraphCypher::PulsarCreateStreamConfigContext::getRuleIndex() const {
  return MemgraphCypher::RulePulsarCreateStreamConfig;
}

void MemgraphCypher::PulsarCreateStreamConfigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPulsarCreateStreamConfig(this);
}

void MemgraphCypher::PulsarCreateStreamConfigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPulsarCreateStreamConfig(this);
}


antlrcpp::Any MemgraphCypher::PulsarCreateStreamConfigContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPulsarCreateStreamConfig(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PulsarCreateStreamConfigContext* MemgraphCypher::pulsarCreateStreamConfig() {
  PulsarCreateStreamConfigContext *_localctx = _tracker.createInstance<PulsarCreateStreamConfigContext>(_ctx, getState());
  enterRule(_localctx, 128, MemgraphCypher::RulePulsarCreateStreamConfig);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(858);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::TOPICS: {
        enterOuterAlt(_localctx, 1);
        setState(853);
        match(MemgraphCypher::TOPICS);
        setState(854);
        topicNames();
        break;
      }

      case MemgraphCypher::SERVICE_URL: {
        enterOuterAlt(_localctx, 2);
        setState(855);
        match(MemgraphCypher::SERVICE_URL);
        setState(856);
        dynamic_cast<PulsarCreateStreamConfigContext *>(_localctx)->serviceUrl = literal();
        break;
      }

      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::TRANSFORM: {
        enterOuterAlt(_localctx, 3);
        setState(857);
        commonCreateStreamConfig();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PulsarCreateStreamContext ------------------------------------------------------------------

MemgraphCypher::PulsarCreateStreamContext::PulsarCreateStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PulsarCreateStreamContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::PulsarCreateStreamContext::PULSAR() {
  return getToken(MemgraphCypher::PULSAR, 0);
}

tree::TerminalNode* MemgraphCypher::PulsarCreateStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::PulsarCreateStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}

std::vector<MemgraphCypher::PulsarCreateStreamConfigContext *> MemgraphCypher::PulsarCreateStreamContext::pulsarCreateStreamConfig() {
  return getRuleContexts<MemgraphCypher::PulsarCreateStreamConfigContext>();
}

MemgraphCypher::PulsarCreateStreamConfigContext* MemgraphCypher::PulsarCreateStreamContext::pulsarCreateStreamConfig(size_t i) {
  return getRuleContext<MemgraphCypher::PulsarCreateStreamConfigContext>(i);
}


size_t MemgraphCypher::PulsarCreateStreamContext::getRuleIndex() const {
  return MemgraphCypher::RulePulsarCreateStream;
}

void MemgraphCypher::PulsarCreateStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPulsarCreateStream(this);
}

void MemgraphCypher::PulsarCreateStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPulsarCreateStream(this);
}


antlrcpp::Any MemgraphCypher::PulsarCreateStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPulsarCreateStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PulsarCreateStreamContext* MemgraphCypher::pulsarCreateStream() {
  PulsarCreateStreamContext *_localctx = _tracker.createInstance<PulsarCreateStreamContext>(_ctx, getState());
  enterRule(_localctx, 130, MemgraphCypher::RulePulsarCreateStream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(860);
    match(MemgraphCypher::CREATE);
    setState(861);
    match(MemgraphCypher::PULSAR);
    setState(862);
    match(MemgraphCypher::STREAM);
    setState(863);
    streamName();
    setState(867);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::BATCH_INTERVAL

    || _la == MemgraphCypher::BATCH_SIZE || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (MemgraphCypher::SERVICE_URL - 65))
      | (1ULL << (MemgraphCypher::TOPICS - 65))
      | (1ULL << (MemgraphCypher::TRANSFORM - 65)))) != 0)) {
      setState(864);
      pulsarCreateStreamConfig();
      setState(869);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropStreamContext ------------------------------------------------------------------

MemgraphCypher::DropStreamContext::DropStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropStreamContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::DropStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}


size_t MemgraphCypher::DropStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropStream;
}

void MemgraphCypher::DropStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropStream(this);
}

void MemgraphCypher::DropStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropStream(this);
}


antlrcpp::Any MemgraphCypher::DropStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropStreamContext* MemgraphCypher::dropStream() {
  DropStreamContext *_localctx = _tracker.createInstance<DropStreamContext>(_ctx, getState());
  enterRule(_localctx, 132, MemgraphCypher::RuleDropStream);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(870);
    match(MemgraphCypher::DROP);
    setState(871);
    match(MemgraphCypher::STREAM);
    setState(872);
    streamName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartStreamContext ------------------------------------------------------------------

MemgraphCypher::StartStreamContext::StartStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::StartStreamContext::START() {
  return getToken(MemgraphCypher::START, 0);
}

tree::TerminalNode* MemgraphCypher::StartStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::StartStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}


size_t MemgraphCypher::StartStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleStartStream;
}

void MemgraphCypher::StartStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartStream(this);
}

void MemgraphCypher::StartStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartStream(this);
}


antlrcpp::Any MemgraphCypher::StartStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStartStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StartStreamContext* MemgraphCypher::startStream() {
  StartStreamContext *_localctx = _tracker.createInstance<StartStreamContext>(_ctx, getState());
  enterRule(_localctx, 134, MemgraphCypher::RuleStartStream);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(874);
    match(MemgraphCypher::START);
    setState(875);
    match(MemgraphCypher::STREAM);
    setState(876);
    streamName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartAllStreamsContext ------------------------------------------------------------------

MemgraphCypher::StartAllStreamsContext::StartAllStreamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::StartAllStreamsContext::START() {
  return getToken(MemgraphCypher::START, 0);
}

tree::TerminalNode* MemgraphCypher::StartAllStreamsContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::StartAllStreamsContext::STREAMS() {
  return getToken(MemgraphCypher::STREAMS, 0);
}


size_t MemgraphCypher::StartAllStreamsContext::getRuleIndex() const {
  return MemgraphCypher::RuleStartAllStreams;
}

void MemgraphCypher::StartAllStreamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartAllStreams(this);
}

void MemgraphCypher::StartAllStreamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartAllStreams(this);
}


antlrcpp::Any MemgraphCypher::StartAllStreamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStartAllStreams(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StartAllStreamsContext* MemgraphCypher::startAllStreams() {
  StartAllStreamsContext *_localctx = _tracker.createInstance<StartAllStreamsContext>(_ctx, getState());
  enterRule(_localctx, 136, MemgraphCypher::RuleStartAllStreams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(878);
    match(MemgraphCypher::START);
    setState(879);
    match(MemgraphCypher::ALL);
    setState(880);
    match(MemgraphCypher::STREAMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StopStreamContext ------------------------------------------------------------------

MemgraphCypher::StopStreamContext::StopStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::StopStreamContext::STOP() {
  return getToken(MemgraphCypher::STOP, 0);
}

tree::TerminalNode* MemgraphCypher::StopStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::StopStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}


size_t MemgraphCypher::StopStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleStopStream;
}

void MemgraphCypher::StopStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStopStream(this);
}

void MemgraphCypher::StopStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStopStream(this);
}


antlrcpp::Any MemgraphCypher::StopStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStopStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StopStreamContext* MemgraphCypher::stopStream() {
  StopStreamContext *_localctx = _tracker.createInstance<StopStreamContext>(_ctx, getState());
  enterRule(_localctx, 138, MemgraphCypher::RuleStopStream);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(882);
    match(MemgraphCypher::STOP);
    setState(883);
    match(MemgraphCypher::STREAM);
    setState(884);
    streamName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StopAllStreamsContext ------------------------------------------------------------------

MemgraphCypher::StopAllStreamsContext::StopAllStreamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::StopAllStreamsContext::STOP() {
  return getToken(MemgraphCypher::STOP, 0);
}

tree::TerminalNode* MemgraphCypher::StopAllStreamsContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::StopAllStreamsContext::STREAMS() {
  return getToken(MemgraphCypher::STREAMS, 0);
}


size_t MemgraphCypher::StopAllStreamsContext::getRuleIndex() const {
  return MemgraphCypher::RuleStopAllStreams;
}

void MemgraphCypher::StopAllStreamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStopAllStreams(this);
}

void MemgraphCypher::StopAllStreamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStopAllStreams(this);
}


antlrcpp::Any MemgraphCypher::StopAllStreamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStopAllStreams(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StopAllStreamsContext* MemgraphCypher::stopAllStreams() {
  StopAllStreamsContext *_localctx = _tracker.createInstance<StopAllStreamsContext>(_ctx, getState());
  enterRule(_localctx, 140, MemgraphCypher::RuleStopAllStreams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(886);
    match(MemgraphCypher::STOP);
    setState(887);
    match(MemgraphCypher::ALL);
    setState(888);
    match(MemgraphCypher::STREAMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowStreamsContext ------------------------------------------------------------------

MemgraphCypher::ShowStreamsContext::ShowStreamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowStreamsContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowStreamsContext::STREAMS() {
  return getToken(MemgraphCypher::STREAMS, 0);
}


size_t MemgraphCypher::ShowStreamsContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowStreams;
}

void MemgraphCypher::ShowStreamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowStreams(this);
}

void MemgraphCypher::ShowStreamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowStreams(this);
}


antlrcpp::Any MemgraphCypher::ShowStreamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowStreams(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowStreamsContext* MemgraphCypher::showStreams() {
  ShowStreamsContext *_localctx = _tracker.createInstance<ShowStreamsContext>(_ctx, getState());
  enterRule(_localctx, 142, MemgraphCypher::RuleShowStreams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(890);
    match(MemgraphCypher::SHOW);
    setState(891);
    match(MemgraphCypher::STREAMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CheckStreamContext ------------------------------------------------------------------

MemgraphCypher::CheckStreamContext::CheckStreamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CheckStreamContext::CHECK() {
  return getToken(MemgraphCypher::CHECK, 0);
}

tree::TerminalNode* MemgraphCypher::CheckStreamContext::STREAM() {
  return getToken(MemgraphCypher::STREAM, 0);
}

MemgraphCypher::StreamNameContext* MemgraphCypher::CheckStreamContext::streamName() {
  return getRuleContext<MemgraphCypher::StreamNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CheckStreamContext::BATCH_LIMIT() {
  return getToken(MemgraphCypher::BATCH_LIMIT, 0);
}

tree::TerminalNode* MemgraphCypher::CheckStreamContext::TIMEOUT() {
  return getToken(MemgraphCypher::TIMEOUT, 0);
}

std::vector<MemgraphCypher::LiteralContext *> MemgraphCypher::CheckStreamContext::literal() {
  return getRuleContexts<MemgraphCypher::LiteralContext>();
}

MemgraphCypher::LiteralContext* MemgraphCypher::CheckStreamContext::literal(size_t i) {
  return getRuleContext<MemgraphCypher::LiteralContext>(i);
}


size_t MemgraphCypher::CheckStreamContext::getRuleIndex() const {
  return MemgraphCypher::RuleCheckStream;
}

void MemgraphCypher::CheckStreamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckStream(this);
}

void MemgraphCypher::CheckStreamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckStream(this);
}


antlrcpp::Any MemgraphCypher::CheckStreamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCheckStream(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CheckStreamContext* MemgraphCypher::checkStream() {
  CheckStreamContext *_localctx = _tracker.createInstance<CheckStreamContext>(_ctx, getState());
  enterRule(_localctx, 144, MemgraphCypher::RuleCheckStream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(893);
    match(MemgraphCypher::CHECK);
    setState(894);
    match(MemgraphCypher::STREAM);
    setState(895);
    streamName();
    setState(898);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::BATCH_LIMIT) {
      setState(896);
      match(MemgraphCypher::BATCH_LIMIT);
      setState(897);
      dynamic_cast<CheckStreamContext *>(_localctx)->batchLimit = literal();
    }
    setState(902);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::TIMEOUT) {
      setState(900);
      match(MemgraphCypher::TIMEOUT);
      setState(901);
      dynamic_cast<CheckStreamContext *>(_localctx)->timeout = literal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingNameContext ------------------------------------------------------------------

MemgraphCypher::SettingNameContext::SettingNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::SettingNameContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::SettingNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleSettingName;
}

void MemgraphCypher::SettingNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingName(this);
}

void MemgraphCypher::SettingNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingName(this);
}


antlrcpp::Any MemgraphCypher::SettingNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSettingName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SettingNameContext* MemgraphCypher::settingName() {
  SettingNameContext *_localctx = _tracker.createInstance<SettingNameContext>(_ctx, getState());
  enterRule(_localctx, 146, MemgraphCypher::RuleSettingName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(904);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingValueContext ------------------------------------------------------------------

MemgraphCypher::SettingValueContext::SettingValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::SettingValueContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}


size_t MemgraphCypher::SettingValueContext::getRuleIndex() const {
  return MemgraphCypher::RuleSettingValue;
}

void MemgraphCypher::SettingValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingValue(this);
}

void MemgraphCypher::SettingValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingValue(this);
}


antlrcpp::Any MemgraphCypher::SettingValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSettingValue(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SettingValueContext* MemgraphCypher::settingValue() {
  SettingValueContext *_localctx = _tracker.createInstance<SettingValueContext>(_ctx, getState());
  enterRule(_localctx, 148, MemgraphCypher::RuleSettingValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(906);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetSettingContext ------------------------------------------------------------------

MemgraphCypher::SetSettingContext::SetSettingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SetSettingContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::SetSettingContext::DATABASE() {
  return getToken(MemgraphCypher::DATABASE, 0);
}

tree::TerminalNode* MemgraphCypher::SetSettingContext::SETTING() {
  return getToken(MemgraphCypher::SETTING, 0);
}

MemgraphCypher::SettingNameContext* MemgraphCypher::SetSettingContext::settingName() {
  return getRuleContext<MemgraphCypher::SettingNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::SetSettingContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

MemgraphCypher::SettingValueContext* MemgraphCypher::SetSettingContext::settingValue() {
  return getRuleContext<MemgraphCypher::SettingValueContext>(0);
}


size_t MemgraphCypher::SetSettingContext::getRuleIndex() const {
  return MemgraphCypher::RuleSetSetting;
}

void MemgraphCypher::SetSettingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetSetting(this);
}

void MemgraphCypher::SetSettingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetSetting(this);
}


antlrcpp::Any MemgraphCypher::SetSettingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSetSetting(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetSettingContext* MemgraphCypher::setSetting() {
  SetSettingContext *_localctx = _tracker.createInstance<SetSettingContext>(_ctx, getState());
  enterRule(_localctx, 150, MemgraphCypher::RuleSetSetting);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(908);
    match(MemgraphCypher::SET);
    setState(909);
    match(MemgraphCypher::DATABASE);
    setState(910);
    match(MemgraphCypher::SETTING);
    setState(911);
    settingName();
    setState(912);
    match(MemgraphCypher::TO);
    setState(913);
    settingValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowSettingContext ------------------------------------------------------------------

MemgraphCypher::ShowSettingContext::ShowSettingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowSettingContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowSettingContext::DATABASE() {
  return getToken(MemgraphCypher::DATABASE, 0);
}

tree::TerminalNode* MemgraphCypher::ShowSettingContext::SETTING() {
  return getToken(MemgraphCypher::SETTING, 0);
}

MemgraphCypher::SettingNameContext* MemgraphCypher::ShowSettingContext::settingName() {
  return getRuleContext<MemgraphCypher::SettingNameContext>(0);
}


size_t MemgraphCypher::ShowSettingContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowSetting;
}

void MemgraphCypher::ShowSettingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowSetting(this);
}

void MemgraphCypher::ShowSettingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowSetting(this);
}


antlrcpp::Any MemgraphCypher::ShowSettingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowSetting(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowSettingContext* MemgraphCypher::showSetting() {
  ShowSettingContext *_localctx = _tracker.createInstance<ShowSettingContext>(_ctx, getState());
  enterRule(_localctx, 152, MemgraphCypher::RuleShowSetting);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(915);
    match(MemgraphCypher::SHOW);
    setState(916);
    match(MemgraphCypher::DATABASE);
    setState(917);
    match(MemgraphCypher::SETTING);
    setState(918);
    settingName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowSettingsContext ------------------------------------------------------------------

MemgraphCypher::ShowSettingsContext::ShowSettingsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ShowSettingsContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::ShowSettingsContext::DATABASE() {
  return getToken(MemgraphCypher::DATABASE, 0);
}

tree::TerminalNode* MemgraphCypher::ShowSettingsContext::SETTINGS() {
  return getToken(MemgraphCypher::SETTINGS, 0);
}


size_t MemgraphCypher::ShowSettingsContext::getRuleIndex() const {
  return MemgraphCypher::RuleShowSettings;
}

void MemgraphCypher::ShowSettingsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowSettings(this);
}

void MemgraphCypher::ShowSettingsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowSettings(this);
}


antlrcpp::Any MemgraphCypher::ShowSettingsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitShowSettings(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ShowSettingsContext* MemgraphCypher::showSettings() {
  ShowSettingsContext *_localctx = _tracker.createInstance<ShowSettingsContext>(_ctx, getState());
  enterRule(_localctx, 154, MemgraphCypher::RuleShowSettings);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(920);
    match(MemgraphCypher::SHOW);
    setState(921);
    match(MemgraphCypher::DATABASE);
    setState(922);
    match(MemgraphCypher::SETTINGS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionQueryContext ------------------------------------------------------------------

MemgraphCypher::VersionQueryContext::VersionQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::VersionQueryContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::VersionQueryContext::VERSION() {
  return getToken(MemgraphCypher::VERSION, 0);
}


size_t MemgraphCypher::VersionQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleVersionQuery;
}

void MemgraphCypher::VersionQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersionQuery(this);
}

void MemgraphCypher::VersionQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersionQuery(this);
}


antlrcpp::Any MemgraphCypher::VersionQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitVersionQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::VersionQueryContext* MemgraphCypher::versionQuery() {
  VersionQueryContext *_localctx = _tracker.createInstance<VersionQueryContext>(_ctx, getState());
  enterRule(_localctx, 156, MemgraphCypher::RuleVersionQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(924);
    match(MemgraphCypher::SHOW);
    setState(925);
    match(MemgraphCypher::VERSION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SnapshotQueryContext ------------------------------------------------------------------

MemgraphCypher::SnapshotQueryContext::SnapshotQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SnapshotQueryContext::SNAPSHOT() {
  return getToken(MemgraphCypher::SNAPSHOT, 0);
}


size_t MemgraphCypher::SnapshotQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleSnapshotQuery;
}

void MemgraphCypher::SnapshotQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSnapshotQuery(this);
}

void MemgraphCypher::SnapshotQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSnapshotQuery(this);
}


antlrcpp::Any MemgraphCypher::SnapshotQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSnapshotQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SnapshotQueryContext* MemgraphCypher::snapshotQuery() {
  SnapshotQueryContext *_localctx = _tracker.createInstance<SnapshotQueryContext>(_ctx, getState());
  enterRule(_localctx, 158, MemgraphCypher::RuleSnapshotQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(927);
    match(MemgraphCypher::SNAPSHOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherContext ------------------------------------------------------------------

MemgraphCypher::CypherContext::CypherContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::StatementContext* MemgraphCypher::CypherContext::statement() {
  return getRuleContext<MemgraphCypher::StatementContext>(0);
}

tree::TerminalNode* MemgraphCypher::CypherContext::EOF() {
  return getToken(MemgraphCypher::EOF, 0);
}

tree::TerminalNode* MemgraphCypher::CypherContext::SEMICOLON() {
  return getToken(MemgraphCypher::SEMICOLON, 0);
}


size_t MemgraphCypher::CypherContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypher;
}

void MemgraphCypher::CypherContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypher(this);
}

void MemgraphCypher::CypherContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypher(this);
}


antlrcpp::Any MemgraphCypher::CypherContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypher(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherContext* MemgraphCypher::cypher() {
  CypherContext *_localctx = _tracker.createInstance<CypherContext>(_ctx, getState());
  enterRule(_localctx, 160, MemgraphCypher::RuleCypher);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(929);
    statement();
    setState(931);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::SEMICOLON) {
      setState(930);
      match(MemgraphCypher::SEMICOLON);
    }
    setState(933);
    match(MemgraphCypher::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MemgraphCypher::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::QueryContext* MemgraphCypher::StatementContext::query() {
  return getRuleContext<MemgraphCypher::QueryContext>(0);
}


size_t MemgraphCypher::StatementContext::getRuleIndex() const {
  return MemgraphCypher::RuleStatement;
}

void MemgraphCypher::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MemgraphCypher::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any MemgraphCypher::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StatementContext* MemgraphCypher::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 162, MemgraphCypher::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(935);
    query();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintQueryContext ------------------------------------------------------------------

MemgraphCypher::ConstraintQueryContext::ConstraintQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ConstraintQueryContext::CONSTRAINT() {
  return getToken(MemgraphCypher::CONSTRAINT, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintQueryContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

MemgraphCypher::ConstraintContext* MemgraphCypher::ConstraintQueryContext::constraint() {
  return getRuleContext<MemgraphCypher::ConstraintContext>(0);
}

tree::TerminalNode* MemgraphCypher::ConstraintQueryContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintQueryContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}


size_t MemgraphCypher::ConstraintQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleConstraintQuery;
}

void MemgraphCypher::ConstraintQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraintQuery(this);
}

void MemgraphCypher::ConstraintQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraintQuery(this);
}


antlrcpp::Any MemgraphCypher::ConstraintQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConstraintQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConstraintQueryContext* MemgraphCypher::constraintQuery() {
  ConstraintQueryContext *_localctx = _tracker.createInstance<ConstraintQueryContext>(_ctx, getState());
  enterRule(_localctx, 164, MemgraphCypher::RuleConstraintQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(937);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::DROP || _la == MemgraphCypher::CREATE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(938);
    match(MemgraphCypher::CONSTRAINT);
    setState(939);
    match(MemgraphCypher::ON);
    setState(940);
    constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintContext ------------------------------------------------------------------

MemgraphCypher::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MemgraphCypher::ConstraintContext::LPAREN() {
  return getTokens(MemgraphCypher::LPAREN);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::LPAREN(size_t i) {
  return getToken(MemgraphCypher::LPAREN, i);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::COLON() {
  return getToken(MemgraphCypher::COLON, 0);
}

MemgraphCypher::LabelNameContext* MemgraphCypher::ConstraintContext::labelName() {
  return getRuleContext<MemgraphCypher::LabelNameContext>(0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ConstraintContext::RPAREN() {
  return getTokens(MemgraphCypher::RPAREN);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::RPAREN(size_t i) {
  return getToken(MemgraphCypher::RPAREN, i);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::ASSERT() {
  return getToken(MemgraphCypher::ASSERT, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::EXISTS() {
  return getToken(MemgraphCypher::EXISTS, 0);
}

MemgraphCypher::ConstraintPropertyListContext* MemgraphCypher::ConstraintContext::constraintPropertyList() {
  return getRuleContext<MemgraphCypher::ConstraintPropertyListContext>(0);
}

MemgraphCypher::VariableContext* MemgraphCypher::ConstraintContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::IS() {
  return getToken(MemgraphCypher::IS, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::UNIQUE() {
  return getToken(MemgraphCypher::UNIQUE, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::NODE() {
  return getToken(MemgraphCypher::NODE, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintContext::KEY() {
  return getToken(MemgraphCypher::KEY, 0);
}


size_t MemgraphCypher::ConstraintContext::getRuleIndex() const {
  return MemgraphCypher::RuleConstraint;
}

void MemgraphCypher::ConstraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraint(this);
}

void MemgraphCypher::ConstraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraint(this);
}


antlrcpp::Any MemgraphCypher::ConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConstraint(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConstraintContext* MemgraphCypher::constraint() {
  ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
  enterRule(_localctx, 166, MemgraphCypher::RuleConstraint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(976);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(942);
      match(MemgraphCypher::LPAREN);
      setState(943);
      dynamic_cast<ConstraintContext *>(_localctx)->nodeName = variable();
      setState(944);
      match(MemgraphCypher::COLON);
      setState(945);
      labelName();
      setState(946);
      match(MemgraphCypher::RPAREN);
      setState(947);
      match(MemgraphCypher::ASSERT);
      setState(948);
      match(MemgraphCypher::EXISTS);
      setState(949);
      match(MemgraphCypher::LPAREN);
      setState(950);
      constraintPropertyList();
      setState(951);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(953);
      match(MemgraphCypher::LPAREN);
      setState(954);
      dynamic_cast<ConstraintContext *>(_localctx)->nodeName = variable();
      setState(955);
      match(MemgraphCypher::COLON);
      setState(956);
      labelName();
      setState(957);
      match(MemgraphCypher::RPAREN);
      setState(958);
      match(MemgraphCypher::ASSERT);
      setState(959);
      constraintPropertyList();
      setState(960);
      match(MemgraphCypher::IS);
      setState(961);
      match(MemgraphCypher::UNIQUE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(963);
      match(MemgraphCypher::LPAREN);
      setState(964);
      dynamic_cast<ConstraintContext *>(_localctx)->nodeName = variable();
      setState(965);
      match(MemgraphCypher::COLON);
      setState(966);
      labelName();
      setState(967);
      match(MemgraphCypher::RPAREN);
      setState(968);
      match(MemgraphCypher::ASSERT);
      setState(969);
      match(MemgraphCypher::LPAREN);
      setState(970);
      constraintPropertyList();
      setState(971);
      match(MemgraphCypher::RPAREN);
      setState(972);
      match(MemgraphCypher::IS);
      setState(973);
      match(MemgraphCypher::NODE);
      setState(974);
      match(MemgraphCypher::KEY);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintPropertyListContext ------------------------------------------------------------------

MemgraphCypher::ConstraintPropertyListContext::ConstraintPropertyListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::VariableContext *> MemgraphCypher::ConstraintPropertyListContext::variable() {
  return getRuleContexts<MemgraphCypher::VariableContext>();
}

MemgraphCypher::VariableContext* MemgraphCypher::ConstraintPropertyListContext::variable(size_t i) {
  return getRuleContext<MemgraphCypher::VariableContext>(i);
}

std::vector<MemgraphCypher::PropertyLookupContext *> MemgraphCypher::ConstraintPropertyListContext::propertyLookup() {
  return getRuleContexts<MemgraphCypher::PropertyLookupContext>();
}

MemgraphCypher::PropertyLookupContext* MemgraphCypher::ConstraintPropertyListContext::propertyLookup(size_t i) {
  return getRuleContext<MemgraphCypher::PropertyLookupContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ConstraintPropertyListContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::ConstraintPropertyListContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::ConstraintPropertyListContext::getRuleIndex() const {
  return MemgraphCypher::RuleConstraintPropertyList;
}

void MemgraphCypher::ConstraintPropertyListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraintPropertyList(this);
}

void MemgraphCypher::ConstraintPropertyListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraintPropertyList(this);
}


antlrcpp::Any MemgraphCypher::ConstraintPropertyListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConstraintPropertyList(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConstraintPropertyListContext* MemgraphCypher::constraintPropertyList() {
  ConstraintPropertyListContext *_localctx = _tracker.createInstance<ConstraintPropertyListContext>(_ctx, getState());
  enterRule(_localctx, 168, MemgraphCypher::RuleConstraintPropertyList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(978);
    variable();
    setState(979);
    propertyLookup();
    setState(986);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(980);
      match(MemgraphCypher::COMMA);
      setState(981);
      variable();
      setState(982);
      propertyLookup();
      setState(988);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageInfoContext ------------------------------------------------------------------

MemgraphCypher::StorageInfoContext::StorageInfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::StorageInfoContext::STORAGE() {
  return getToken(MemgraphCypher::STORAGE, 0);
}

tree::TerminalNode* MemgraphCypher::StorageInfoContext::INFO() {
  return getToken(MemgraphCypher::INFO, 0);
}


size_t MemgraphCypher::StorageInfoContext::getRuleIndex() const {
  return MemgraphCypher::RuleStorageInfo;
}

void MemgraphCypher::StorageInfoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorageInfo(this);
}

void MemgraphCypher::StorageInfoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorageInfo(this);
}


antlrcpp::Any MemgraphCypher::StorageInfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStorageInfo(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StorageInfoContext* MemgraphCypher::storageInfo() {
  StorageInfoContext *_localctx = _tracker.createInstance<StorageInfoContext>(_ctx, getState());
  enterRule(_localctx, 170, MemgraphCypher::RuleStorageInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(989);
    match(MemgraphCypher::STORAGE);
    setState(990);
    match(MemgraphCypher::INFO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexInfoContext ------------------------------------------------------------------

MemgraphCypher::IndexInfoContext::IndexInfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::IndexInfoContext::INDEX() {
  return getToken(MemgraphCypher::INDEX, 0);
}

tree::TerminalNode* MemgraphCypher::IndexInfoContext::INFO() {
  return getToken(MemgraphCypher::INFO, 0);
}


size_t MemgraphCypher::IndexInfoContext::getRuleIndex() const {
  return MemgraphCypher::RuleIndexInfo;
}

void MemgraphCypher::IndexInfoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexInfo(this);
}

void MemgraphCypher::IndexInfoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexInfo(this);
}


antlrcpp::Any MemgraphCypher::IndexInfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIndexInfo(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IndexInfoContext* MemgraphCypher::indexInfo() {
  IndexInfoContext *_localctx = _tracker.createInstance<IndexInfoContext>(_ctx, getState());
  enterRule(_localctx, 172, MemgraphCypher::RuleIndexInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(992);
    match(MemgraphCypher::INDEX);
    setState(993);
    match(MemgraphCypher::INFO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstraintInfoContext ------------------------------------------------------------------

MemgraphCypher::ConstraintInfoContext::ConstraintInfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ConstraintInfoContext::CONSTRAINT() {
  return getToken(MemgraphCypher::CONSTRAINT, 0);
}

tree::TerminalNode* MemgraphCypher::ConstraintInfoContext::INFO() {
  return getToken(MemgraphCypher::INFO, 0);
}


size_t MemgraphCypher::ConstraintInfoContext::getRuleIndex() const {
  return MemgraphCypher::RuleConstraintInfo;
}

void MemgraphCypher::ConstraintInfoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraintInfo(this);
}

void MemgraphCypher::ConstraintInfoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraintInfo(this);
}


antlrcpp::Any MemgraphCypher::ConstraintInfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitConstraintInfo(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ConstraintInfoContext* MemgraphCypher::constraintInfo() {
  ConstraintInfoContext *_localctx = _tracker.createInstance<ConstraintInfoContext>(_ctx, getState());
  enterRule(_localctx, 174, MemgraphCypher::RuleConstraintInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(995);
    match(MemgraphCypher::CONSTRAINT);
    setState(996);
    match(MemgraphCypher::INFO);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InfoQueryContext ------------------------------------------------------------------

MemgraphCypher::InfoQueryContext::InfoQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::InfoQueryContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

MemgraphCypher::StorageInfoContext* MemgraphCypher::InfoQueryContext::storageInfo() {
  return getRuleContext<MemgraphCypher::StorageInfoContext>(0);
}

MemgraphCypher::IndexInfoContext* MemgraphCypher::InfoQueryContext::indexInfo() {
  return getRuleContext<MemgraphCypher::IndexInfoContext>(0);
}

MemgraphCypher::ConstraintInfoContext* MemgraphCypher::InfoQueryContext::constraintInfo() {
  return getRuleContext<MemgraphCypher::ConstraintInfoContext>(0);
}


size_t MemgraphCypher::InfoQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleInfoQuery;
}

void MemgraphCypher::InfoQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInfoQuery(this);
}

void MemgraphCypher::InfoQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInfoQuery(this);
}


antlrcpp::Any MemgraphCypher::InfoQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitInfoQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::InfoQueryContext* MemgraphCypher::infoQuery() {
  InfoQueryContext *_localctx = _tracker.createInstance<InfoQueryContext>(_ctx, getState());
  enterRule(_localctx, 176, MemgraphCypher::RuleInfoQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(998);
    match(MemgraphCypher::SHOW);
    setState(1002);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::STORAGE: {
        setState(999);
        storageInfo();
        break;
      }

      case MemgraphCypher::INDEX: {
        setState(1000);
        indexInfo();
        break;
      }

      case MemgraphCypher::CONSTRAINT: {
        setState(1001);
        constraintInfo();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplainQueryContext ------------------------------------------------------------------

MemgraphCypher::ExplainQueryContext::ExplainQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ExplainQueryContext::EXPLAIN() {
  return getToken(MemgraphCypher::EXPLAIN, 0);
}

MemgraphCypher::CypherQueryContext* MemgraphCypher::ExplainQueryContext::cypherQuery() {
  return getRuleContext<MemgraphCypher::CypherQueryContext>(0);
}


size_t MemgraphCypher::ExplainQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleExplainQuery;
}

void MemgraphCypher::ExplainQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplainQuery(this);
}

void MemgraphCypher::ExplainQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplainQuery(this);
}


antlrcpp::Any MemgraphCypher::ExplainQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExplainQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ExplainQueryContext* MemgraphCypher::explainQuery() {
  ExplainQueryContext *_localctx = _tracker.createInstance<ExplainQueryContext>(_ctx, getState());
  enterRule(_localctx, 178, MemgraphCypher::RuleExplainQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1004);
    match(MemgraphCypher::EXPLAIN);
    setState(1005);
    cypherQuery();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProfileQueryContext ------------------------------------------------------------------

MemgraphCypher::ProfileQueryContext::ProfileQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ProfileQueryContext::PROFILE() {
  return getToken(MemgraphCypher::PROFILE, 0);
}

MemgraphCypher::CypherQueryContext* MemgraphCypher::ProfileQueryContext::cypherQuery() {
  return getRuleContext<MemgraphCypher::CypherQueryContext>(0);
}


size_t MemgraphCypher::ProfileQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleProfileQuery;
}

void MemgraphCypher::ProfileQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProfileQuery(this);
}

void MemgraphCypher::ProfileQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProfileQuery(this);
}


antlrcpp::Any MemgraphCypher::ProfileQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitProfileQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ProfileQueryContext* MemgraphCypher::profileQuery() {
  ProfileQueryContext *_localctx = _tracker.createInstance<ProfileQueryContext>(_ctx, getState());
  enterRule(_localctx, 180, MemgraphCypher::RuleProfileQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1007);
    match(MemgraphCypher::PROFILE);
    setState(1008);
    cypherQuery();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherQueryContext ------------------------------------------------------------------

MemgraphCypher::CypherQueryContext::CypherQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SingleQueryContext* MemgraphCypher::CypherQueryContext::singleQuery() {
  return getRuleContext<MemgraphCypher::SingleQueryContext>(0);
}

std::vector<MemgraphCypher::CypherUnionContext *> MemgraphCypher::CypherQueryContext::cypherUnion() {
  return getRuleContexts<MemgraphCypher::CypherUnionContext>();
}

MemgraphCypher::CypherUnionContext* MemgraphCypher::CypherQueryContext::cypherUnion(size_t i) {
  return getRuleContext<MemgraphCypher::CypherUnionContext>(i);
}

MemgraphCypher::QueryMemoryLimitContext* MemgraphCypher::CypherQueryContext::queryMemoryLimit() {
  return getRuleContext<MemgraphCypher::QueryMemoryLimitContext>(0);
}


size_t MemgraphCypher::CypherQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherQuery;
}

void MemgraphCypher::CypherQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherQuery(this);
}

void MemgraphCypher::CypherQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherQuery(this);
}


antlrcpp::Any MemgraphCypher::CypherQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherQueryContext* MemgraphCypher::cypherQuery() {
  CypherQueryContext *_localctx = _tracker.createInstance<CypherQueryContext>(_ctx, getState());
  enterRule(_localctx, 182, MemgraphCypher::RuleCypherQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1010);
    singleQuery();
    setState(1014);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::UNION) {
      setState(1011);
      cypherUnion();
      setState(1016);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1018);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::QUERY) {
      setState(1017);
      queryMemoryLimit();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexQueryContext ------------------------------------------------------------------

MemgraphCypher::IndexQueryContext::IndexQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::CreateIndexContext* MemgraphCypher::IndexQueryContext::createIndex() {
  return getRuleContext<MemgraphCypher::CreateIndexContext>(0);
}

MemgraphCypher::DropIndexContext* MemgraphCypher::IndexQueryContext::dropIndex() {
  return getRuleContext<MemgraphCypher::DropIndexContext>(0);
}


size_t MemgraphCypher::IndexQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleIndexQuery;
}

void MemgraphCypher::IndexQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexQuery(this);
}

void MemgraphCypher::IndexQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexQuery(this);
}


antlrcpp::Any MemgraphCypher::IndexQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIndexQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IndexQueryContext* MemgraphCypher::indexQuery() {
  IndexQueryContext *_localctx = _tracker.createInstance<IndexQueryContext>(_ctx, getState());
  enterRule(_localctx, 184, MemgraphCypher::RuleIndexQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1022);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::CREATE: {
        enterOuterAlt(_localctx, 1);
        setState(1020);
        createIndex();
        break;
      }

      case MemgraphCypher::DROP: {
        enterOuterAlt(_localctx, 2);
        setState(1021);
        dropIndex();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleQueryContext ------------------------------------------------------------------

MemgraphCypher::SingleQueryContext::SingleQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::ClauseContext *> MemgraphCypher::SingleQueryContext::clause() {
  return getRuleContexts<MemgraphCypher::ClauseContext>();
}

MemgraphCypher::ClauseContext* MemgraphCypher::SingleQueryContext::clause(size_t i) {
  return getRuleContext<MemgraphCypher::ClauseContext>(i);
}


size_t MemgraphCypher::SingleQueryContext::getRuleIndex() const {
  return MemgraphCypher::RuleSingleQuery;
}

void MemgraphCypher::SingleQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleQuery(this);
}

void MemgraphCypher::SingleQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleQuery(this);
}


antlrcpp::Any MemgraphCypher::SingleQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSingleQuery(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SingleQueryContext* MemgraphCypher::singleQuery() {
  SingleQueryContext *_localctx = _tracker.createInstance<SingleQueryContext>(_ctx, getState());
  enterRule(_localctx, 186, MemgraphCypher::RuleSingleQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1024);
    clause();
    setState(1028);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::LOAD || ((((_la - 131) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 131)) & ((1ULL << (MemgraphCypher::CALL - 131))
      | (1ULL << (MemgraphCypher::CREATE - 131))
      | (1ULL << (MemgraphCypher::DELETE - 131))
      | (1ULL << (MemgraphCypher::DETACH - 131))
      | (1ULL << (MemgraphCypher::MATCH - 131))
      | (1ULL << (MemgraphCypher::MERGE - 131))
      | (1ULL << (MemgraphCypher::OPTIONAL - 131))
      | (1ULL << (MemgraphCypher::REMOVE - 131))
      | (1ULL << (MemgraphCypher::RETURN - 131))
      | (1ULL << (MemgraphCypher::SET - 131))
      | (1ULL << (MemgraphCypher::UNWIND - 131))
      | (1ULL << (MemgraphCypher::WITH - 131)))) != 0)) {
      setState(1025);
      clause();
      setState(1030);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherUnionContext ------------------------------------------------------------------

MemgraphCypher::CypherUnionContext::CypherUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CypherUnionContext::UNION() {
  return getToken(MemgraphCypher::UNION, 0);
}

tree::TerminalNode* MemgraphCypher::CypherUnionContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

MemgraphCypher::SingleQueryContext* MemgraphCypher::CypherUnionContext::singleQuery() {
  return getRuleContext<MemgraphCypher::SingleQueryContext>(0);
}


size_t MemgraphCypher::CypherUnionContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherUnion;
}

void MemgraphCypher::CypherUnionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherUnion(this);
}

void MemgraphCypher::CypherUnionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherUnion(this);
}


antlrcpp::Any MemgraphCypher::CypherUnionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherUnion(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherUnionContext* MemgraphCypher::cypherUnion() {
  CypherUnionContext *_localctx = _tracker.createInstance<CypherUnionContext>(_ctx, getState());
  enterRule(_localctx, 188, MemgraphCypher::RuleCypherUnion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1036);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1031);
      match(MemgraphCypher::UNION);
      setState(1032);
      match(MemgraphCypher::ALL);
      setState(1033);
      singleQuery();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1034);
      match(MemgraphCypher::UNION);
      setState(1035);
      singleQuery();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherMatchContext ------------------------------------------------------------------

MemgraphCypher::CypherMatchContext::CypherMatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CypherMatchContext::MATCH() {
  return getToken(MemgraphCypher::MATCH, 0);
}

MemgraphCypher::PatternContext* MemgraphCypher::CypherMatchContext::pattern() {
  return getRuleContext<MemgraphCypher::PatternContext>(0);
}

tree::TerminalNode* MemgraphCypher::CypherMatchContext::OPTIONAL() {
  return getToken(MemgraphCypher::OPTIONAL, 0);
}

MemgraphCypher::WhereContext* MemgraphCypher::CypherMatchContext::where() {
  return getRuleContext<MemgraphCypher::WhereContext>(0);
}

MemgraphCypher::TtContext* MemgraphCypher::CypherMatchContext::tt() {
  return getRuleContext<MemgraphCypher::TtContext>(0);
}

MemgraphCypher::VtContext* MemgraphCypher::CypherMatchContext::vt() {
  return getRuleContext<MemgraphCypher::VtContext>(0);
}


size_t MemgraphCypher::CypherMatchContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherMatch;
}

void MemgraphCypher::CypherMatchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherMatch(this);
}

void MemgraphCypher::CypherMatchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherMatch(this);
}


antlrcpp::Any MemgraphCypher::CypherMatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherMatch(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherMatchContext* MemgraphCypher::cypherMatch() {
  CypherMatchContext *_localctx = _tracker.createInstance<CypherMatchContext>(_ctx, getState());
  enterRule(_localctx, 190, MemgraphCypher::RuleCypherMatch);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1039);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::OPTIONAL) {
      setState(1038);
      match(MemgraphCypher::OPTIONAL);
    }
    setState(1041);
    match(MemgraphCypher::MATCH);
    setState(1042);
    pattern();
    setState(1044);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WHERE) {
      setState(1043);
      where();
    }
    setState(1047);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::TT) {
      setState(1046);
      tt();
    }
    setState(1050);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::VT) {
      setState(1049);
      vt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TtContext ------------------------------------------------------------------

MemgraphCypher::TtContext::TtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::TtContext::TT() {
  return getToken(MemgraphCypher::TT, 0);
}

tree::TerminalNode* MemgraphCypher::TtContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

std::vector<MemgraphCypher::LiteralContext *> MemgraphCypher::TtContext::literal() {
  return getRuleContexts<MemgraphCypher::LiteralContext>();
}

MemgraphCypher::LiteralContext* MemgraphCypher::TtContext::literal(size_t i) {
  return getRuleContext<MemgraphCypher::LiteralContext>(i);
}

tree::TerminalNode* MemgraphCypher::TtContext::FROM() {
  return getToken(MemgraphCypher::FROM, 0);
}

tree::TerminalNode* MemgraphCypher::TtContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}


size_t MemgraphCypher::TtContext::getRuleIndex() const {
  return MemgraphCypher::RuleTt;
}

void MemgraphCypher::TtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTt(this);
}

void MemgraphCypher::TtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTt(this);
}


antlrcpp::Any MemgraphCypher::TtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitTt(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::TtContext* MemgraphCypher::tt() {
  TtContext *_localctx = _tracker.createInstance<TtContext>(_ctx, getState());
  enterRule(_localctx, 192, MemgraphCypher::RuleTt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1061);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1052);
      match(MemgraphCypher::TT);
      setState(1053);
      match(MemgraphCypher::AS);
      setState(1054);
      dynamic_cast<TtContext *>(_localctx)->as_literal = literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1055);
      match(MemgraphCypher::TT);
      setState(1056);
      match(MemgraphCypher::FROM);
      setState(1057);
      dynamic_cast<TtContext *>(_localctx)->from_literal = literal();
      setState(1058);
      match(MemgraphCypher::TO);
      setState(1059);
      dynamic_cast<TtContext *>(_localctx)->to_literal = literal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VtContext ------------------------------------------------------------------

MemgraphCypher::VtContext::VtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::VtContext::VT() {
  return getToken(MemgraphCypher::VT, 0);
}

tree::TerminalNode* MemgraphCypher::VtContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

std::vector<MemgraphCypher::LiteralContext *> MemgraphCypher::VtContext::literal() {
  return getRuleContexts<MemgraphCypher::LiteralContext>();
}

MemgraphCypher::LiteralContext* MemgraphCypher::VtContext::literal(size_t i) {
  return getRuleContext<MemgraphCypher::LiteralContext>(i);
}

tree::TerminalNode* MemgraphCypher::VtContext::From() {
  return getToken(MemgraphCypher::From, 0);
}

tree::TerminalNode* MemgraphCypher::VtContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}


size_t MemgraphCypher::VtContext::getRuleIndex() const {
  return MemgraphCypher::RuleVt;
}

void MemgraphCypher::VtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVt(this);
}

void MemgraphCypher::VtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVt(this);
}


antlrcpp::Any MemgraphCypher::VtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitVt(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::VtContext* MemgraphCypher::vt() {
  VtContext *_localctx = _tracker.createInstance<VtContext>(_ctx, getState());
  enterRule(_localctx, 194, MemgraphCypher::RuleVt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1072);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1063);
      match(MemgraphCypher::VT);
      setState(1064);
      match(MemgraphCypher::AS);
      setState(1065);
      dynamic_cast<VtContext *>(_localctx)->as_vliteral = literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1066);
      match(MemgraphCypher::VT);
      setState(1067);
      match(MemgraphCypher::From);
      setState(1068);
      dynamic_cast<VtContext *>(_localctx)->from_vliteral = literal();
      setState(1069);
      match(MemgraphCypher::TO);
      setState(1070);
      dynamic_cast<VtContext *>(_localctx)->to_vliteral = literal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnwindContext ------------------------------------------------------------------

MemgraphCypher::UnwindContext::UnwindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::UnwindContext::UNWIND() {
  return getToken(MemgraphCypher::UNWIND, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::UnwindContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::UnwindContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

MemgraphCypher::VariableContext* MemgraphCypher::UnwindContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}


size_t MemgraphCypher::UnwindContext::getRuleIndex() const {
  return MemgraphCypher::RuleUnwind;
}

void MemgraphCypher::UnwindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnwind(this);
}

void MemgraphCypher::UnwindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnwind(this);
}


antlrcpp::Any MemgraphCypher::UnwindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitUnwind(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::UnwindContext* MemgraphCypher::unwind() {
  UnwindContext *_localctx = _tracker.createInstance<UnwindContext>(_ctx, getState());
  enterRule(_localctx, 196, MemgraphCypher::RuleUnwind);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1074);
    match(MemgraphCypher::UNWIND);
    setState(1075);
    expression();
    setState(1076);
    match(MemgraphCypher::AS);
    setState(1077);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MergeContext ------------------------------------------------------------------

MemgraphCypher::MergeContext::MergeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::MergeContext::MERGE() {
  return getToken(MemgraphCypher::MERGE, 0);
}

MemgraphCypher::PatternPartContext* MemgraphCypher::MergeContext::patternPart() {
  return getRuleContext<MemgraphCypher::PatternPartContext>(0);
}

std::vector<MemgraphCypher::MergeActionContext *> MemgraphCypher::MergeContext::mergeAction() {
  return getRuleContexts<MemgraphCypher::MergeActionContext>();
}

MemgraphCypher::MergeActionContext* MemgraphCypher::MergeContext::mergeAction(size_t i) {
  return getRuleContext<MemgraphCypher::MergeActionContext>(i);
}


size_t MemgraphCypher::MergeContext::getRuleIndex() const {
  return MemgraphCypher::RuleMerge;
}

void MemgraphCypher::MergeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMerge(this);
}

void MemgraphCypher::MergeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMerge(this);
}


antlrcpp::Any MemgraphCypher::MergeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitMerge(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::MergeContext* MemgraphCypher::merge() {
  MergeContext *_localctx = _tracker.createInstance<MergeContext>(_ctx, getState());
  enterRule(_localctx, 198, MemgraphCypher::RuleMerge);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1079);
    match(MemgraphCypher::MERGE);
    setState(1080);
    patternPart();
    setState(1084);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::ON) {
      setState(1081);
      mergeAction();
      setState(1086);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MergeActionContext ------------------------------------------------------------------

MemgraphCypher::MergeActionContext::MergeActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::MergeActionContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

tree::TerminalNode* MemgraphCypher::MergeActionContext::MATCH() {
  return getToken(MemgraphCypher::MATCH, 0);
}

MemgraphCypher::SetContext* MemgraphCypher::MergeActionContext::set() {
  return getRuleContext<MemgraphCypher::SetContext>(0);
}

tree::TerminalNode* MemgraphCypher::MergeActionContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}


size_t MemgraphCypher::MergeActionContext::getRuleIndex() const {
  return MemgraphCypher::RuleMergeAction;
}

void MemgraphCypher::MergeActionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMergeAction(this);
}

void MemgraphCypher::MergeActionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMergeAction(this);
}


antlrcpp::Any MemgraphCypher::MergeActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitMergeAction(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::MergeActionContext* MemgraphCypher::mergeAction() {
  MergeActionContext *_localctx = _tracker.createInstance<MergeActionContext>(_ctx, getState());
  enterRule(_localctx, 200, MemgraphCypher::RuleMergeAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1093);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1087);
      match(MemgraphCypher::ON);
      setState(1088);
      match(MemgraphCypher::MATCH);
      setState(1089);
      set();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1090);
      match(MemgraphCypher::ON);
      setState(1091);
      match(MemgraphCypher::CREATE);
      setState(1092);
      set();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateContext ------------------------------------------------------------------

MemgraphCypher::CreateContext::CreateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CreateContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

MemgraphCypher::PatternContext* MemgraphCypher::CreateContext::pattern() {
  return getRuleContext<MemgraphCypher::PatternContext>(0);
}


size_t MemgraphCypher::CreateContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreate;
}

void MemgraphCypher::CreateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate(this);
}

void MemgraphCypher::CreateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate(this);
}


antlrcpp::Any MemgraphCypher::CreateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreate(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateContext* MemgraphCypher::create() {
  CreateContext *_localctx = _tracker.createInstance<CreateContext>(_ctx, getState());
  enterRule(_localctx, 202, MemgraphCypher::RuleCreate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1095);
    match(MemgraphCypher::CREATE);
    setState(1096);
    pattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetContext ------------------------------------------------------------------

MemgraphCypher::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SetContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

std::vector<MemgraphCypher::SetItemContext *> MemgraphCypher::SetContext::setItem() {
  return getRuleContexts<MemgraphCypher::SetItemContext>();
}

MemgraphCypher::SetItemContext* MemgraphCypher::SetContext::setItem(size_t i) {
  return getRuleContext<MemgraphCypher::SetItemContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::SetContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::SetContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::SetContext::getRuleIndex() const {
  return MemgraphCypher::RuleSet;
}

void MemgraphCypher::SetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet(this);
}

void MemgraphCypher::SetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet(this);
}


antlrcpp::Any MemgraphCypher::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetContext* MemgraphCypher::set() {
  SetContext *_localctx = _tracker.createInstance<SetContext>(_ctx, getState());
  enterRule(_localctx, 204, MemgraphCypher::RuleSet);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1098);
    match(MemgraphCypher::SET);
    setState(1099);
    setItem();
    setState(1104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(1100);
      match(MemgraphCypher::COMMA);
      setState(1101);
      setItem();
      setState(1106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetItemContext ------------------------------------------------------------------

MemgraphCypher::SetItemContext::SetItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::PropertyExpressionContext* MemgraphCypher::SetItemContext::propertyExpression() {
  return getRuleContext<MemgraphCypher::PropertyExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::SetItemContext::EQ() {
  return getToken(MemgraphCypher::EQ, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::SetItemContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

MemgraphCypher::VariableContext* MemgraphCypher::SetItemContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

tree::TerminalNode* MemgraphCypher::SetItemContext::PLUS_EQ() {
  return getToken(MemgraphCypher::PLUS_EQ, 0);
}

MemgraphCypher::NodeLabelsContext* MemgraphCypher::SetItemContext::nodeLabels() {
  return getRuleContext<MemgraphCypher::NodeLabelsContext>(0);
}


size_t MemgraphCypher::SetItemContext::getRuleIndex() const {
  return MemgraphCypher::RuleSetItem;
}

void MemgraphCypher::SetItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetItem(this);
}

void MemgraphCypher::SetItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetItem(this);
}


antlrcpp::Any MemgraphCypher::SetItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSetItem(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SetItemContext* MemgraphCypher::setItem() {
  SetItemContext *_localctx = _tracker.createInstance<SetItemContext>(_ctx, getState());
  enterRule(_localctx, 206, MemgraphCypher::RuleSetItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1107);
      propertyExpression();
      setState(1108);
      match(MemgraphCypher::EQ);
      setState(1109);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1111);
      variable();
      setState(1112);
      match(MemgraphCypher::EQ);
      setState(1113);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1115);
      variable();
      setState(1116);
      match(MemgraphCypher::PLUS_EQ);
      setState(1117);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1119);
      variable();
      setState(1120);
      nodeLabels();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherDeleteContext ------------------------------------------------------------------

MemgraphCypher::CypherDeleteContext::CypherDeleteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CypherDeleteContext::DELETE() {
  return getToken(MemgraphCypher::DELETE, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::CypherDeleteContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::CypherDeleteContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

tree::TerminalNode* MemgraphCypher::CypherDeleteContext::DETACH() {
  return getToken(MemgraphCypher::DETACH, 0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::CypherDeleteContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::CypherDeleteContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::CypherDeleteContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherDelete;
}

void MemgraphCypher::CypherDeleteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherDelete(this);
}

void MemgraphCypher::CypherDeleteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherDelete(this);
}


antlrcpp::Any MemgraphCypher::CypherDeleteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherDelete(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherDeleteContext* MemgraphCypher::cypherDelete() {
  CypherDeleteContext *_localctx = _tracker.createInstance<CypherDeleteContext>(_ctx, getState());
  enterRule(_localctx, 208, MemgraphCypher::RuleCypherDelete);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::DETACH) {
      setState(1124);
      match(MemgraphCypher::DETACH);
    }
    setState(1127);
    match(MemgraphCypher::DELETE);
    setState(1128);
    expression();
    setState(1133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(1129);
      match(MemgraphCypher::COMMA);
      setState(1130);
      expression();
      setState(1135);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RemoveContext ------------------------------------------------------------------

MemgraphCypher::RemoveContext::RemoveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RemoveContext::REMOVE() {
  return getToken(MemgraphCypher::REMOVE, 0);
}

std::vector<MemgraphCypher::RemoveItemContext *> MemgraphCypher::RemoveContext::removeItem() {
  return getRuleContexts<MemgraphCypher::RemoveItemContext>();
}

MemgraphCypher::RemoveItemContext* MemgraphCypher::RemoveContext::removeItem(size_t i) {
  return getRuleContext<MemgraphCypher::RemoveItemContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::RemoveContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::RemoveContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::RemoveContext::getRuleIndex() const {
  return MemgraphCypher::RuleRemove;
}

void MemgraphCypher::RemoveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRemove(this);
}

void MemgraphCypher::RemoveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRemove(this);
}


antlrcpp::Any MemgraphCypher::RemoveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRemove(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RemoveContext* MemgraphCypher::remove() {
  RemoveContext *_localctx = _tracker.createInstance<RemoveContext>(_ctx, getState());
  enterRule(_localctx, 210, MemgraphCypher::RuleRemove);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1136);
    match(MemgraphCypher::REMOVE);
    setState(1137);
    removeItem();
    setState(1142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(1138);
      match(MemgraphCypher::COMMA);
      setState(1139);
      removeItem();
      setState(1144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RemoveItemContext ------------------------------------------------------------------

MemgraphCypher::RemoveItemContext::RemoveItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::VariableContext* MemgraphCypher::RemoveItemContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

MemgraphCypher::NodeLabelsContext* MemgraphCypher::RemoveItemContext::nodeLabels() {
  return getRuleContext<MemgraphCypher::NodeLabelsContext>(0);
}

MemgraphCypher::PropertyExpressionContext* MemgraphCypher::RemoveItemContext::propertyExpression() {
  return getRuleContext<MemgraphCypher::PropertyExpressionContext>(0);
}


size_t MemgraphCypher::RemoveItemContext::getRuleIndex() const {
  return MemgraphCypher::RuleRemoveItem;
}

void MemgraphCypher::RemoveItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRemoveItem(this);
}

void MemgraphCypher::RemoveItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRemoveItem(this);
}


antlrcpp::Any MemgraphCypher::RemoveItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRemoveItem(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RemoveItemContext* MemgraphCypher::removeItem() {
  RemoveItemContext *_localctx = _tracker.createInstance<RemoveItemContext>(_ctx, getState());
  enterRule(_localctx, 212, MemgraphCypher::RuleRemoveItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1145);
      variable();
      setState(1146);
      nodeLabels();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1148);
      propertyExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithContext ------------------------------------------------------------------

MemgraphCypher::WithContext::WithContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::WithContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

MemgraphCypher::ReturnBodyContext* MemgraphCypher::WithContext::returnBody() {
  return getRuleContext<MemgraphCypher::ReturnBodyContext>(0);
}

tree::TerminalNode* MemgraphCypher::WithContext::DISTINCT() {
  return getToken(MemgraphCypher::DISTINCT, 0);
}

MemgraphCypher::WhereContext* MemgraphCypher::WithContext::where() {
  return getRuleContext<MemgraphCypher::WhereContext>(0);
}


size_t MemgraphCypher::WithContext::getRuleIndex() const {
  return MemgraphCypher::RuleWith;
}

void MemgraphCypher::WithContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWith(this);
}

void MemgraphCypher::WithContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWith(this);
}


antlrcpp::Any MemgraphCypher::WithContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitWith(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::WithContext* MemgraphCypher::with() {
  WithContext *_localctx = _tracker.createInstance<WithContext>(_ctx, getState());
  enterRule(_localctx, 214, MemgraphCypher::RuleWith);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1151);
    match(MemgraphCypher::WITH);
    setState(1153);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(1152);
      match(MemgraphCypher::DISTINCT);
      break;
    }

    default:
      break;
    }
    setState(1155);
    returnBody();
    setState(1157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WHERE) {
      setState(1156);
      where();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherReturnContext ------------------------------------------------------------------

MemgraphCypher::CypherReturnContext::CypherReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CypherReturnContext::RETURN() {
  return getToken(MemgraphCypher::RETURN, 0);
}

MemgraphCypher::ReturnBodyContext* MemgraphCypher::CypherReturnContext::returnBody() {
  return getRuleContext<MemgraphCypher::ReturnBodyContext>(0);
}

tree::TerminalNode* MemgraphCypher::CypherReturnContext::DISTINCT() {
  return getToken(MemgraphCypher::DISTINCT, 0);
}


size_t MemgraphCypher::CypherReturnContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherReturn;
}

void MemgraphCypher::CypherReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherReturn(this);
}

void MemgraphCypher::CypherReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherReturn(this);
}


antlrcpp::Any MemgraphCypher::CypherReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherReturn(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherReturnContext* MemgraphCypher::cypherReturn() {
  CypherReturnContext *_localctx = _tracker.createInstance<CypherReturnContext>(_ctx, getState());
  enterRule(_localctx, 216, MemgraphCypher::RuleCypherReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1159);
    match(MemgraphCypher::RETURN);
    setState(1161);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      setState(1160);
      match(MemgraphCypher::DISTINCT);
      break;
    }

    default:
      break;
    }
    setState(1163);
    returnBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallProcedureContext ------------------------------------------------------------------

MemgraphCypher::CallProcedureContext::CallProcedureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CallProcedureContext::CALL() {
  return getToken(MemgraphCypher::CALL, 0);
}

MemgraphCypher::ProcedureNameContext* MemgraphCypher::CallProcedureContext::procedureName() {
  return getRuleContext<MemgraphCypher::ProcedureNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CallProcedureContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::CallProcedureContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::CallProcedureContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::CallProcedureContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

MemgraphCypher::ProcedureMemoryLimitContext* MemgraphCypher::CallProcedureContext::procedureMemoryLimit() {
  return getRuleContext<MemgraphCypher::ProcedureMemoryLimitContext>(0);
}

MemgraphCypher::YieldProcedureResultsContext* MemgraphCypher::CallProcedureContext::yieldProcedureResults() {
  return getRuleContext<MemgraphCypher::YieldProcedureResultsContext>(0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::CallProcedureContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::CallProcedureContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::CallProcedureContext::getRuleIndex() const {
  return MemgraphCypher::RuleCallProcedure;
}

void MemgraphCypher::CallProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallProcedure(this);
}

void MemgraphCypher::CallProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallProcedure(this);
}


antlrcpp::Any MemgraphCypher::CallProcedureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCallProcedure(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CallProcedureContext* MemgraphCypher::callProcedure() {
  CallProcedureContext *_localctx = _tracker.createInstance<CallProcedureContext>(_ctx, getState());
  enterRule(_localctx, 218, MemgraphCypher::RuleCallProcedure);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1165);
    match(MemgraphCypher::CALL);
    setState(1166);
    procedureName();
    setState(1167);
    match(MemgraphCypher::LPAREN);
    setState(1176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::LPAREN - 64))
      | (1ULL << (MemgraphCypher::LBRACK - 64))
      | (1ULL << (MemgraphCypher::LBRACE - 64))
      | (1ULL << (MemgraphCypher::DOLLAR - 64))
      | (1ULL << (MemgraphCypher::PLUS - 64))
      | (1ULL << (MemgraphCypher::MINUS - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::COALESCE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::StringLiteral - 192))
      | (1ULL << (MemgraphCypher::DecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::OctalLiteral - 192))
      | (1ULL << (MemgraphCypher::HexadecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::FloatingLiteral - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1168);
      expression();
      setState(1173);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(1169);
        match(MemgraphCypher::COMMA);
        setState(1170);
        expression();
        setState(1175);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1178);
    match(MemgraphCypher::RPAREN);
    setState(1180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::PROCEDURE) {
      setState(1179);
      procedureMemoryLimit();
    }
    setState(1183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::YIELD) {
      setState(1182);
      yieldProcedureResults();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

MemgraphCypher::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::SymbolicNameContext *> MemgraphCypher::ProcedureNameContext::symbolicName() {
  return getRuleContexts<MemgraphCypher::SymbolicNameContext>();
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::ProcedureNameContext::symbolicName(size_t i) {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ProcedureNameContext::DOT() {
  return getTokens(MemgraphCypher::DOT);
}

tree::TerminalNode* MemgraphCypher::ProcedureNameContext::DOT(size_t i) {
  return getToken(MemgraphCypher::DOT, i);
}


size_t MemgraphCypher::ProcedureNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleProcedureName;
}

void MemgraphCypher::ProcedureNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureName(this);
}

void MemgraphCypher::ProcedureNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureName(this);
}


antlrcpp::Any MemgraphCypher::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ProcedureNameContext* MemgraphCypher::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 220, MemgraphCypher::RuleProcedureName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1185);
    symbolicName();
    setState(1190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::DOT) {
      setState(1186);
      match(MemgraphCypher::DOT);
      setState(1187);
      symbolicName();
      setState(1192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YieldProcedureResultsContext ------------------------------------------------------------------

MemgraphCypher::YieldProcedureResultsContext::YieldProcedureResultsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::YieldProcedureResultsContext::YIELD() {
  return getToken(MemgraphCypher::YIELD, 0);
}

tree::TerminalNode* MemgraphCypher::YieldProcedureResultsContext::ASTERISK() {
  return getToken(MemgraphCypher::ASTERISK, 0);
}

std::vector<MemgraphCypher::ProcedureResultContext *> MemgraphCypher::YieldProcedureResultsContext::procedureResult() {
  return getRuleContexts<MemgraphCypher::ProcedureResultContext>();
}

MemgraphCypher::ProcedureResultContext* MemgraphCypher::YieldProcedureResultsContext::procedureResult(size_t i) {
  return getRuleContext<MemgraphCypher::ProcedureResultContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::YieldProcedureResultsContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::YieldProcedureResultsContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::YieldProcedureResultsContext::getRuleIndex() const {
  return MemgraphCypher::RuleYieldProcedureResults;
}

void MemgraphCypher::YieldProcedureResultsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldProcedureResults(this);
}

void MemgraphCypher::YieldProcedureResultsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldProcedureResults(this);
}


antlrcpp::Any MemgraphCypher::YieldProcedureResultsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitYieldProcedureResults(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::YieldProcedureResultsContext* MemgraphCypher::yieldProcedureResults() {
  YieldProcedureResultsContext *_localctx = _tracker.createInstance<YieldProcedureResultsContext>(_ctx, getState());
  enterRule(_localctx, 222, MemgraphCypher::RuleYieldProcedureResults);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1193);
    match(MemgraphCypher::YIELD);
    setState(1203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::ASTERISK: {
        setState(1194);
        match(MemgraphCypher::ASTERISK);
        break;
      }

      case MemgraphCypher::AFTER:
      case MemgraphCypher::ALTER:
      case MemgraphCypher::ASYNC:
      case MemgraphCypher::AUTH:
      case MemgraphCypher::BAD:
      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_LIMIT:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::BEFORE:
      case MemgraphCypher::BOOTSTRAP_SERVERS:
      case MemgraphCypher::CHECK:
      case MemgraphCypher::CLEAR:
      case MemgraphCypher::COMMIT:
      case MemgraphCypher::COMMITTED:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::CONFIGS:
      case MemgraphCypher::CONSUMER_GROUP:
      case MemgraphCypher::CREDENTIALS:
      case MemgraphCypher::CSV:
      case MemgraphCypher::DATA:
      case MemgraphCypher::DELIMITER:
      case MemgraphCypher::DATABASE:
      case MemgraphCypher::DENY:
      case MemgraphCypher::DROP:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::EXECUTE:
      case MemgraphCypher::FOR:
      case MemgraphCypher::FREE:
      case MemgraphCypher::FROM:
      case MemgraphCypher::GLOBAL:
      case MemgraphCypher::GRANT:
      case MemgraphCypher::HEADER:
      case MemgraphCypher::IDENTIFIED:
      case MemgraphCypher::ISOLATION:
      case MemgraphCypher::KAFKA:
      case MemgraphCypher::LEVEL:
      case MemgraphCypher::LOAD:
      case MemgraphCypher::LOCK:
      case MemgraphCypher::MAIN:
      case MemgraphCypher::MODE:
      case MemgraphCypher::NEXT:
      case MemgraphCypher::NO:
      case MemgraphCypher::PASSWORD:
      case MemgraphCypher::PORT:
      case MemgraphCypher::PRIVILEGES:
      case MemgraphCypher::PULSAR:
      case MemgraphCypher::READ:
      case MemgraphCypher::REGISTER:
      case MemgraphCypher::REPLICA:
      case MemgraphCypher::REPLICAS:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::REVOKE:
      case MemgraphCypher::ROLE:
      case MemgraphCypher::ROLES:
      case MemgraphCypher::QUOTE:
      case MemgraphCypher::SESSION:
      case MemgraphCypher::SETTING:
      case MemgraphCypher::SETTINGS:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::START:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::STREAMS:
      case MemgraphCypher::SYNC:
      case MemgraphCypher::TIMEOUT:
      case MemgraphCypher::TO:
      case MemgraphCypher::TOPICS:
      case MemgraphCypher::TRANSACTION:
      case MemgraphCypher::TRANSFORM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::TRIGGERS:
      case MemgraphCypher::UNCOMMITTED:
      case MemgraphCypher::UNLOCK:
      case MemgraphCypher::UPDATE:
      case MemgraphCypher::USER:
      case MemgraphCypher::USERS:
      case MemgraphCypher::VERSION:
      case MemgraphCypher::ALL:
      case MemgraphCypher::AND:
      case MemgraphCypher::ANY:
      case MemgraphCypher::AS:
      case MemgraphCypher::ASC:
      case MemgraphCypher::ASCENDING:
      case MemgraphCypher::ASSERT:
      case MemgraphCypher::BFS:
      case MemgraphCypher::BY:
      case MemgraphCypher::CALL:
      case MemgraphCypher::CASE:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CONTAINS:
      case MemgraphCypher::COUNT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::CYPHERNULL:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::DESC:
      case MemgraphCypher::DESCENDING:
      case MemgraphCypher::DETACH:
      case MemgraphCypher::DISTINCT:
      case MemgraphCypher::ELSE:
      case MemgraphCypher::END:
      case MemgraphCypher::ENDS:
      case MemgraphCypher::EXISTS:
      case MemgraphCypher::EXPLAIN:
      case MemgraphCypher::EXTRACT:
      case MemgraphCypher::FALSE:
      case MemgraphCypher::FILTER:
      case MemgraphCypher::IN:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::INFO:
      case MemgraphCypher::IS:
      case MemgraphCypher::KEY:
      case MemgraphCypher::LIMIT:
      case MemgraphCypher::L_SKIP:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::NODE:
      case MemgraphCypher::NONE:
      case MemgraphCypher::NOT:
      case MemgraphCypher::ON:
      case MemgraphCypher::OPTIONAL:
      case MemgraphCypher::OR:
      case MemgraphCypher::ORDER:
      case MemgraphCypher::PROCEDURE:
      case MemgraphCypher::PROFILE:
      case MemgraphCypher::QUERY:
      case MemgraphCypher::REDUCE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::RETURN:
      case MemgraphCypher::SET:
      case MemgraphCypher::SHOW:
      case MemgraphCypher::SINGLE:
      case MemgraphCypher::STARTS:
      case MemgraphCypher::STORAGE:
      case MemgraphCypher::THEN:
      case MemgraphCypher::TRUE:
      case MemgraphCypher::TT:
      case MemgraphCypher::UNION:
      case MemgraphCypher::UNIQUE:
      case MemgraphCypher::UNWIND:
      case MemgraphCypher::WHEN:
      case MemgraphCypher::WHERE:
      case MemgraphCypher::WITH:
      case MemgraphCypher::WSHORTEST:
      case MemgraphCypher::XOR:
      case MemgraphCypher::YIELD:
      case MemgraphCypher::UnescapedSymbolicName:
      case MemgraphCypher::EscapedSymbolicName: {
        setState(1195);
        procedureResult();
        setState(1200);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MemgraphCypher::COMMA) {
          setState(1196);
          match(MemgraphCypher::COMMA);
          setState(1197);
          procedureResult();
          setState(1202);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemoryLimitContext ------------------------------------------------------------------

MemgraphCypher::MemoryLimitContext::MemoryLimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::MemoryLimitContext::MEMORY() {
  return getToken(MemgraphCypher::MEMORY, 0);
}

tree::TerminalNode* MemgraphCypher::MemoryLimitContext::UNLIMITED() {
  return getToken(MemgraphCypher::UNLIMITED, 0);
}

tree::TerminalNode* MemgraphCypher::MemoryLimitContext::LIMIT() {
  return getToken(MemgraphCypher::LIMIT, 0);
}

MemgraphCypher::LiteralContext* MemgraphCypher::MemoryLimitContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}

tree::TerminalNode* MemgraphCypher::MemoryLimitContext::MB() {
  return getToken(MemgraphCypher::MB, 0);
}

tree::TerminalNode* MemgraphCypher::MemoryLimitContext::KB() {
  return getToken(MemgraphCypher::KB, 0);
}


size_t MemgraphCypher::MemoryLimitContext::getRuleIndex() const {
  return MemgraphCypher::RuleMemoryLimit;
}

void MemgraphCypher::MemoryLimitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemoryLimit(this);
}

void MemgraphCypher::MemoryLimitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemoryLimit(this);
}


antlrcpp::Any MemgraphCypher::MemoryLimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitMemoryLimit(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::MemoryLimitContext* MemgraphCypher::memoryLimit() {
  MemoryLimitContext *_localctx = _tracker.createInstance<MemoryLimitContext>(_ctx, getState());
  enterRule(_localctx, 224, MemgraphCypher::RuleMemoryLimit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1205);
    match(MemgraphCypher::MEMORY);
    setState(1211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::UNLIMITED: {
        setState(1206);
        match(MemgraphCypher::UNLIMITED);
        break;
      }

      case MemgraphCypher::LIMIT: {
        setState(1207);
        match(MemgraphCypher::LIMIT);
        setState(1208);
        literal();
        setState(1209);
        _la = _input->LA(1);
        if (!(_la == MemgraphCypher::KB

        || _la == MemgraphCypher::MB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryMemoryLimitContext ------------------------------------------------------------------

MemgraphCypher::QueryMemoryLimitContext::QueryMemoryLimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::QueryMemoryLimitContext::QUERY() {
  return getToken(MemgraphCypher::QUERY, 0);
}

MemgraphCypher::MemoryLimitContext* MemgraphCypher::QueryMemoryLimitContext::memoryLimit() {
  return getRuleContext<MemgraphCypher::MemoryLimitContext>(0);
}


size_t MemgraphCypher::QueryMemoryLimitContext::getRuleIndex() const {
  return MemgraphCypher::RuleQueryMemoryLimit;
}

void MemgraphCypher::QueryMemoryLimitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryMemoryLimit(this);
}

void MemgraphCypher::QueryMemoryLimitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryMemoryLimit(this);
}


antlrcpp::Any MemgraphCypher::QueryMemoryLimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitQueryMemoryLimit(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::QueryMemoryLimitContext* MemgraphCypher::queryMemoryLimit() {
  QueryMemoryLimitContext *_localctx = _tracker.createInstance<QueryMemoryLimitContext>(_ctx, getState());
  enterRule(_localctx, 226, MemgraphCypher::RuleQueryMemoryLimit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1213);
    match(MemgraphCypher::QUERY);
    setState(1214);
    memoryLimit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureMemoryLimitContext ------------------------------------------------------------------

MemgraphCypher::ProcedureMemoryLimitContext::ProcedureMemoryLimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ProcedureMemoryLimitContext::PROCEDURE() {
  return getToken(MemgraphCypher::PROCEDURE, 0);
}

MemgraphCypher::MemoryLimitContext* MemgraphCypher::ProcedureMemoryLimitContext::memoryLimit() {
  return getRuleContext<MemgraphCypher::MemoryLimitContext>(0);
}


size_t MemgraphCypher::ProcedureMemoryLimitContext::getRuleIndex() const {
  return MemgraphCypher::RuleProcedureMemoryLimit;
}

void MemgraphCypher::ProcedureMemoryLimitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureMemoryLimit(this);
}

void MemgraphCypher::ProcedureMemoryLimitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureMemoryLimit(this);
}


antlrcpp::Any MemgraphCypher::ProcedureMemoryLimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitProcedureMemoryLimit(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ProcedureMemoryLimitContext* MemgraphCypher::procedureMemoryLimit() {
  ProcedureMemoryLimitContext *_localctx = _tracker.createInstance<ProcedureMemoryLimitContext>(_ctx, getState());
  enterRule(_localctx, 228, MemgraphCypher::RuleProcedureMemoryLimit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1216);
    match(MemgraphCypher::PROCEDURE);
    setState(1217);
    memoryLimit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureResultContext ------------------------------------------------------------------

MemgraphCypher::ProcedureResultContext::ProcedureResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::VariableContext *> MemgraphCypher::ProcedureResultContext::variable() {
  return getRuleContexts<MemgraphCypher::VariableContext>();
}

MemgraphCypher::VariableContext* MemgraphCypher::ProcedureResultContext::variable(size_t i) {
  return getRuleContext<MemgraphCypher::VariableContext>(i);
}

tree::TerminalNode* MemgraphCypher::ProcedureResultContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}


size_t MemgraphCypher::ProcedureResultContext::getRuleIndex() const {
  return MemgraphCypher::RuleProcedureResult;
}

void MemgraphCypher::ProcedureResultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureResult(this);
}

void MemgraphCypher::ProcedureResultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureResult(this);
}


antlrcpp::Any MemgraphCypher::ProcedureResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitProcedureResult(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ProcedureResultContext* MemgraphCypher::procedureResult() {
  ProcedureResultContext *_localctx = _tracker.createInstance<ProcedureResultContext>(_ctx, getState());
  enterRule(_localctx, 230, MemgraphCypher::RuleProcedureResult);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1219);
      variable();
      setState(1220);
      match(MemgraphCypher::AS);
      setState(1221);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1223);
      variable();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnBodyContext ------------------------------------------------------------------

MemgraphCypher::ReturnBodyContext::ReturnBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::ReturnItemsContext* MemgraphCypher::ReturnBodyContext::returnItems() {
  return getRuleContext<MemgraphCypher::ReturnItemsContext>(0);
}

MemgraphCypher::OrderContext* MemgraphCypher::ReturnBodyContext::order() {
  return getRuleContext<MemgraphCypher::OrderContext>(0);
}

MemgraphCypher::SkipContext* MemgraphCypher::ReturnBodyContext::skip() {
  return getRuleContext<MemgraphCypher::SkipContext>(0);
}

MemgraphCypher::LimitContext* MemgraphCypher::ReturnBodyContext::limit() {
  return getRuleContext<MemgraphCypher::LimitContext>(0);
}


size_t MemgraphCypher::ReturnBodyContext::getRuleIndex() const {
  return MemgraphCypher::RuleReturnBody;
}

void MemgraphCypher::ReturnBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnBody(this);
}

void MemgraphCypher::ReturnBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnBody(this);
}


antlrcpp::Any MemgraphCypher::ReturnBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReturnBody(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReturnBodyContext* MemgraphCypher::returnBody() {
  ReturnBodyContext *_localctx = _tracker.createInstance<ReturnBodyContext>(_ctx, getState());
  enterRule(_localctx, 232, MemgraphCypher::RuleReturnBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1226);
    returnItems();
    setState(1228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::ORDER) {
      setState(1227);
      order();
    }
    setState(1231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::L_SKIP) {
      setState(1230);
      skip();
    }
    setState(1234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::LIMIT) {
      setState(1233);
      limit();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemsContext ------------------------------------------------------------------

MemgraphCypher::ReturnItemsContext::ReturnItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ReturnItemsContext::ASTERISK() {
  return getToken(MemgraphCypher::ASTERISK, 0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ReturnItemsContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::ReturnItemsContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}

std::vector<MemgraphCypher::ReturnItemContext *> MemgraphCypher::ReturnItemsContext::returnItem() {
  return getRuleContexts<MemgraphCypher::ReturnItemContext>();
}

MemgraphCypher::ReturnItemContext* MemgraphCypher::ReturnItemsContext::returnItem(size_t i) {
  return getRuleContext<MemgraphCypher::ReturnItemContext>(i);
}


size_t MemgraphCypher::ReturnItemsContext::getRuleIndex() const {
  return MemgraphCypher::RuleReturnItems;
}

void MemgraphCypher::ReturnItemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnItems(this);
}

void MemgraphCypher::ReturnItemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnItems(this);
}


antlrcpp::Any MemgraphCypher::ReturnItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReturnItems(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReturnItemsContext* MemgraphCypher::returnItems() {
  ReturnItemsContext *_localctx = _tracker.createInstance<ReturnItemsContext>(_ctx, getState());
  enterRule(_localctx, 234, MemgraphCypher::RuleReturnItems);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::ASTERISK: {
        enterOuterAlt(_localctx, 1);
        setState(1236);
        match(MemgraphCypher::ASTERISK);
        setState(1241);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MemgraphCypher::COMMA) {
          setState(1237);
          match(MemgraphCypher::COMMA);
          setState(1238);
          returnItem();
          setState(1243);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case MemgraphCypher::AFTER:
      case MemgraphCypher::ALTER:
      case MemgraphCypher::ASYNC:
      case MemgraphCypher::AUTH:
      case MemgraphCypher::BAD:
      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_LIMIT:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::BEFORE:
      case MemgraphCypher::BOOTSTRAP_SERVERS:
      case MemgraphCypher::CHECK:
      case MemgraphCypher::CLEAR:
      case MemgraphCypher::COMMIT:
      case MemgraphCypher::COMMITTED:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::CONFIGS:
      case MemgraphCypher::CONSUMER_GROUP:
      case MemgraphCypher::CREDENTIALS:
      case MemgraphCypher::CSV:
      case MemgraphCypher::DATA:
      case MemgraphCypher::DELIMITER:
      case MemgraphCypher::DATABASE:
      case MemgraphCypher::DENY:
      case MemgraphCypher::DROP:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::EXECUTE:
      case MemgraphCypher::FOR:
      case MemgraphCypher::FREE:
      case MemgraphCypher::FROM:
      case MemgraphCypher::GLOBAL:
      case MemgraphCypher::GRANT:
      case MemgraphCypher::HEADER:
      case MemgraphCypher::IDENTIFIED:
      case MemgraphCypher::ISOLATION:
      case MemgraphCypher::KAFKA:
      case MemgraphCypher::LEVEL:
      case MemgraphCypher::LOAD:
      case MemgraphCypher::LOCK:
      case MemgraphCypher::MAIN:
      case MemgraphCypher::MODE:
      case MemgraphCypher::NEXT:
      case MemgraphCypher::NO:
      case MemgraphCypher::PASSWORD:
      case MemgraphCypher::PORT:
      case MemgraphCypher::PRIVILEGES:
      case MemgraphCypher::PULSAR:
      case MemgraphCypher::READ:
      case MemgraphCypher::REGISTER:
      case MemgraphCypher::REPLICA:
      case MemgraphCypher::REPLICAS:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::REVOKE:
      case MemgraphCypher::ROLE:
      case MemgraphCypher::ROLES:
      case MemgraphCypher::QUOTE:
      case MemgraphCypher::SESSION:
      case MemgraphCypher::SETTING:
      case MemgraphCypher::SETTINGS:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::START:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::STREAMS:
      case MemgraphCypher::SYNC:
      case MemgraphCypher::TIMEOUT:
      case MemgraphCypher::TO:
      case MemgraphCypher::TOPICS:
      case MemgraphCypher::TRANSACTION:
      case MemgraphCypher::TRANSFORM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::TRIGGERS:
      case MemgraphCypher::UNCOMMITTED:
      case MemgraphCypher::UNLOCK:
      case MemgraphCypher::UPDATE:
      case MemgraphCypher::USER:
      case MemgraphCypher::USERS:
      case MemgraphCypher::VERSION:
      case MemgraphCypher::LPAREN:
      case MemgraphCypher::LBRACK:
      case MemgraphCypher::LBRACE:
      case MemgraphCypher::DOLLAR:
      case MemgraphCypher::PLUS:
      case MemgraphCypher::MINUS:
      case MemgraphCypher::ALL:
      case MemgraphCypher::AND:
      case MemgraphCypher::ANY:
      case MemgraphCypher::AS:
      case MemgraphCypher::ASC:
      case MemgraphCypher::ASCENDING:
      case MemgraphCypher::ASSERT:
      case MemgraphCypher::BFS:
      case MemgraphCypher::BY:
      case MemgraphCypher::CALL:
      case MemgraphCypher::CASE:
      case MemgraphCypher::COALESCE:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CONTAINS:
      case MemgraphCypher::COUNT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::CYPHERNULL:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::DESC:
      case MemgraphCypher::DESCENDING:
      case MemgraphCypher::DETACH:
      case MemgraphCypher::DISTINCT:
      case MemgraphCypher::ELSE:
      case MemgraphCypher::END:
      case MemgraphCypher::ENDS:
      case MemgraphCypher::EXISTS:
      case MemgraphCypher::EXPLAIN:
      case MemgraphCypher::EXTRACT:
      case MemgraphCypher::FALSE:
      case MemgraphCypher::FILTER:
      case MemgraphCypher::IN:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::INFO:
      case MemgraphCypher::IS:
      case MemgraphCypher::KEY:
      case MemgraphCypher::LIMIT:
      case MemgraphCypher::L_SKIP:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::NODE:
      case MemgraphCypher::NONE:
      case MemgraphCypher::NOT:
      case MemgraphCypher::ON:
      case MemgraphCypher::OPTIONAL:
      case MemgraphCypher::OR:
      case MemgraphCypher::ORDER:
      case MemgraphCypher::PROCEDURE:
      case MemgraphCypher::PROFILE:
      case MemgraphCypher::QUERY:
      case MemgraphCypher::REDUCE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::RETURN:
      case MemgraphCypher::SET:
      case MemgraphCypher::SHOW:
      case MemgraphCypher::SINGLE:
      case MemgraphCypher::STARTS:
      case MemgraphCypher::STORAGE:
      case MemgraphCypher::THEN:
      case MemgraphCypher::TRUE:
      case MemgraphCypher::TT:
      case MemgraphCypher::UNION:
      case MemgraphCypher::UNIQUE:
      case MemgraphCypher::UNWIND:
      case MemgraphCypher::WHEN:
      case MemgraphCypher::WHERE:
      case MemgraphCypher::WITH:
      case MemgraphCypher::WSHORTEST:
      case MemgraphCypher::XOR:
      case MemgraphCypher::YIELD:
      case MemgraphCypher::StringLiteral:
      case MemgraphCypher::DecimalLiteral:
      case MemgraphCypher::OctalLiteral:
      case MemgraphCypher::HexadecimalLiteral:
      case MemgraphCypher::FloatingLiteral:
      case MemgraphCypher::UnescapedSymbolicName:
      case MemgraphCypher::EscapedSymbolicName: {
        enterOuterAlt(_localctx, 2);
        setState(1244);
        returnItem();
        setState(1249);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MemgraphCypher::COMMA) {
          setState(1245);
          match(MemgraphCypher::COMMA);
          setState(1246);
          returnItem();
          setState(1251);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemContext ------------------------------------------------------------------

MemgraphCypher::ReturnItemContext::ReturnItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ReturnItemContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::ReturnItemContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

MemgraphCypher::VariableContext* MemgraphCypher::ReturnItemContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}


size_t MemgraphCypher::ReturnItemContext::getRuleIndex() const {
  return MemgraphCypher::RuleReturnItem;
}

void MemgraphCypher::ReturnItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnItem(this);
}

void MemgraphCypher::ReturnItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnItem(this);
}


antlrcpp::Any MemgraphCypher::ReturnItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReturnItem(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReturnItemContext* MemgraphCypher::returnItem() {
  ReturnItemContext *_localctx = _tracker.createInstance<ReturnItemContext>(_ctx, getState());
  enterRule(_localctx, 236, MemgraphCypher::RuleReturnItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1254);
      expression();
      setState(1255);
      match(MemgraphCypher::AS);
      setState(1256);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1258);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderContext ------------------------------------------------------------------

MemgraphCypher::OrderContext::OrderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::OrderContext::ORDER() {
  return getToken(MemgraphCypher::ORDER, 0);
}

tree::TerminalNode* MemgraphCypher::OrderContext::BY() {
  return getToken(MemgraphCypher::BY, 0);
}

std::vector<MemgraphCypher::SortItemContext *> MemgraphCypher::OrderContext::sortItem() {
  return getRuleContexts<MemgraphCypher::SortItemContext>();
}

MemgraphCypher::SortItemContext* MemgraphCypher::OrderContext::sortItem(size_t i) {
  return getRuleContext<MemgraphCypher::SortItemContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::OrderContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::OrderContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::OrderContext::getRuleIndex() const {
  return MemgraphCypher::RuleOrder;
}

void MemgraphCypher::OrderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrder(this);
}

void MemgraphCypher::OrderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrder(this);
}


antlrcpp::Any MemgraphCypher::OrderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitOrder(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::OrderContext* MemgraphCypher::order() {
  OrderContext *_localctx = _tracker.createInstance<OrderContext>(_ctx, getState());
  enterRule(_localctx, 238, MemgraphCypher::RuleOrder);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1261);
    match(MemgraphCypher::ORDER);
    setState(1262);
    match(MemgraphCypher::BY);
    setState(1263);
    sortItem();
    setState(1268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(1264);
      match(MemgraphCypher::COMMA);
      setState(1265);
      sortItem();
      setState(1270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkipContext ------------------------------------------------------------------

MemgraphCypher::SkipContext::SkipContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::SkipContext::L_SKIP() {
  return getToken(MemgraphCypher::L_SKIP, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::SkipContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::SkipContext::getRuleIndex() const {
  return MemgraphCypher::RuleSkip;
}

void MemgraphCypher::SkipContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkip(this);
}

void MemgraphCypher::SkipContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkip(this);
}


antlrcpp::Any MemgraphCypher::SkipContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSkip(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SkipContext* MemgraphCypher::skip() {
  SkipContext *_localctx = _tracker.createInstance<SkipContext>(_ctx, getState());
  enterRule(_localctx, 240, MemgraphCypher::RuleSkip);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1271);
    match(MemgraphCypher::L_SKIP);
    setState(1272);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LimitContext ------------------------------------------------------------------

MemgraphCypher::LimitContext::LimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::LimitContext::LIMIT() {
  return getToken(MemgraphCypher::LIMIT, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::LimitContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::LimitContext::getRuleIndex() const {
  return MemgraphCypher::RuleLimit;
}

void MemgraphCypher::LimitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLimit(this);
}

void MemgraphCypher::LimitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLimit(this);
}


antlrcpp::Any MemgraphCypher::LimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLimit(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LimitContext* MemgraphCypher::limit() {
  LimitContext *_localctx = _tracker.createInstance<LimitContext>(_ctx, getState());
  enterRule(_localctx, 242, MemgraphCypher::RuleLimit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1274);
    match(MemgraphCypher::LIMIT);
    setState(1275);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortItemContext ------------------------------------------------------------------

MemgraphCypher::SortItemContext::SortItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::ExpressionContext* MemgraphCypher::SortItemContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::SortItemContext::ASCENDING() {
  return getToken(MemgraphCypher::ASCENDING, 0);
}

tree::TerminalNode* MemgraphCypher::SortItemContext::ASC() {
  return getToken(MemgraphCypher::ASC, 0);
}

tree::TerminalNode* MemgraphCypher::SortItemContext::DESCENDING() {
  return getToken(MemgraphCypher::DESCENDING, 0);
}

tree::TerminalNode* MemgraphCypher::SortItemContext::DESC() {
  return getToken(MemgraphCypher::DESC, 0);
}


size_t MemgraphCypher::SortItemContext::getRuleIndex() const {
  return MemgraphCypher::RuleSortItem;
}

void MemgraphCypher::SortItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSortItem(this);
}

void MemgraphCypher::SortItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSortItem(this);
}


antlrcpp::Any MemgraphCypher::SortItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitSortItem(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::SortItemContext* MemgraphCypher::sortItem() {
  SortItemContext *_localctx = _tracker.createInstance<SortItemContext>(_ctx, getState());
  enterRule(_localctx, 244, MemgraphCypher::RuleSortItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1277);
    expression();
    setState(1279);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 126) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 126)) & ((1ULL << (MemgraphCypher::ASC - 126))
      | (1ULL << (MemgraphCypher::ASCENDING - 126))
      | (1ULL << (MemgraphCypher::DESC - 126))
      | (1ULL << (MemgraphCypher::DESCENDING - 126)))) != 0)) {
      setState(1278);
      _la = _input->LA(1);
      if (!(((((_la - 126) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 126)) & ((1ULL << (MemgraphCypher::ASC - 126))
        | (1ULL << (MemgraphCypher::ASCENDING - 126))
        | (1ULL << (MemgraphCypher::DESC - 126))
        | (1ULL << (MemgraphCypher::DESCENDING - 126)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereContext ------------------------------------------------------------------

MemgraphCypher::WhereContext::WhereContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::WhereContext::WHERE() {
  return getToken(MemgraphCypher::WHERE, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::WhereContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::WhereContext::getRuleIndex() const {
  return MemgraphCypher::RuleWhere;
}

void MemgraphCypher::WhereContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere(this);
}

void MemgraphCypher::WhereContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere(this);
}


antlrcpp::Any MemgraphCypher::WhereContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitWhere(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::WhereContext* MemgraphCypher::where() {
  WhereContext *_localctx = _tracker.createInstance<WhereContext>(_ctx, getState());
  enterRule(_localctx, 246, MemgraphCypher::RuleWhere);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1281);
    match(MemgraphCypher::WHERE);
    setState(1282);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

MemgraphCypher::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::PatternPartContext *> MemgraphCypher::PatternContext::patternPart() {
  return getRuleContexts<MemgraphCypher::PatternPartContext>();
}

MemgraphCypher::PatternPartContext* MemgraphCypher::PatternContext::patternPart(size_t i) {
  return getRuleContext<MemgraphCypher::PatternPartContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::PatternContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::PatternContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::PatternContext::getRuleIndex() const {
  return MemgraphCypher::RulePattern;
}

void MemgraphCypher::PatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern(this);
}

void MemgraphCypher::PatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern(this);
}


antlrcpp::Any MemgraphCypher::PatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPattern(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PatternContext* MemgraphCypher::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 248, MemgraphCypher::RulePattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1284);
    patternPart();
    setState(1289);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COMMA) {
      setState(1285);
      match(MemgraphCypher::COMMA);
      setState(1286);
      patternPart();
      setState(1291);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternPartContext ------------------------------------------------------------------

MemgraphCypher::PatternPartContext::PatternPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::VariableContext* MemgraphCypher::PatternPartContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

tree::TerminalNode* MemgraphCypher::PatternPartContext::EQ() {
  return getToken(MemgraphCypher::EQ, 0);
}

MemgraphCypher::AnonymousPatternPartContext* MemgraphCypher::PatternPartContext::anonymousPatternPart() {
  return getRuleContext<MemgraphCypher::AnonymousPatternPartContext>(0);
}


size_t MemgraphCypher::PatternPartContext::getRuleIndex() const {
  return MemgraphCypher::RulePatternPart;
}

void MemgraphCypher::PatternPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternPart(this);
}

void MemgraphCypher::PatternPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternPart(this);
}


antlrcpp::Any MemgraphCypher::PatternPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPatternPart(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PatternPartContext* MemgraphCypher::patternPart() {
  PatternPartContext *_localctx = _tracker.createInstance<PatternPartContext>(_ctx, getState());
  enterRule(_localctx, 250, MemgraphCypher::RulePatternPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1297);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::AFTER:
      case MemgraphCypher::ALTER:
      case MemgraphCypher::ASYNC:
      case MemgraphCypher::AUTH:
      case MemgraphCypher::BAD:
      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_LIMIT:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::BEFORE:
      case MemgraphCypher::BOOTSTRAP_SERVERS:
      case MemgraphCypher::CHECK:
      case MemgraphCypher::CLEAR:
      case MemgraphCypher::COMMIT:
      case MemgraphCypher::COMMITTED:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::CONFIGS:
      case MemgraphCypher::CONSUMER_GROUP:
      case MemgraphCypher::CREDENTIALS:
      case MemgraphCypher::CSV:
      case MemgraphCypher::DATA:
      case MemgraphCypher::DELIMITER:
      case MemgraphCypher::DATABASE:
      case MemgraphCypher::DENY:
      case MemgraphCypher::DROP:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::EXECUTE:
      case MemgraphCypher::FOR:
      case MemgraphCypher::FREE:
      case MemgraphCypher::FROM:
      case MemgraphCypher::GLOBAL:
      case MemgraphCypher::GRANT:
      case MemgraphCypher::HEADER:
      case MemgraphCypher::IDENTIFIED:
      case MemgraphCypher::ISOLATION:
      case MemgraphCypher::KAFKA:
      case MemgraphCypher::LEVEL:
      case MemgraphCypher::LOAD:
      case MemgraphCypher::LOCK:
      case MemgraphCypher::MAIN:
      case MemgraphCypher::MODE:
      case MemgraphCypher::NEXT:
      case MemgraphCypher::NO:
      case MemgraphCypher::PASSWORD:
      case MemgraphCypher::PORT:
      case MemgraphCypher::PRIVILEGES:
      case MemgraphCypher::PULSAR:
      case MemgraphCypher::READ:
      case MemgraphCypher::REGISTER:
      case MemgraphCypher::REPLICA:
      case MemgraphCypher::REPLICAS:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::REVOKE:
      case MemgraphCypher::ROLE:
      case MemgraphCypher::ROLES:
      case MemgraphCypher::QUOTE:
      case MemgraphCypher::SESSION:
      case MemgraphCypher::SETTING:
      case MemgraphCypher::SETTINGS:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::START:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::STREAMS:
      case MemgraphCypher::SYNC:
      case MemgraphCypher::TIMEOUT:
      case MemgraphCypher::TO:
      case MemgraphCypher::TOPICS:
      case MemgraphCypher::TRANSACTION:
      case MemgraphCypher::TRANSFORM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::TRIGGERS:
      case MemgraphCypher::UNCOMMITTED:
      case MemgraphCypher::UNLOCK:
      case MemgraphCypher::UPDATE:
      case MemgraphCypher::USER:
      case MemgraphCypher::USERS:
      case MemgraphCypher::VERSION:
      case MemgraphCypher::ALL:
      case MemgraphCypher::AND:
      case MemgraphCypher::ANY:
      case MemgraphCypher::AS:
      case MemgraphCypher::ASC:
      case MemgraphCypher::ASCENDING:
      case MemgraphCypher::ASSERT:
      case MemgraphCypher::BFS:
      case MemgraphCypher::BY:
      case MemgraphCypher::CALL:
      case MemgraphCypher::CASE:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CONTAINS:
      case MemgraphCypher::COUNT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::CYPHERNULL:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::DESC:
      case MemgraphCypher::DESCENDING:
      case MemgraphCypher::DETACH:
      case MemgraphCypher::DISTINCT:
      case MemgraphCypher::ELSE:
      case MemgraphCypher::END:
      case MemgraphCypher::ENDS:
      case MemgraphCypher::EXISTS:
      case MemgraphCypher::EXPLAIN:
      case MemgraphCypher::EXTRACT:
      case MemgraphCypher::FALSE:
      case MemgraphCypher::FILTER:
      case MemgraphCypher::IN:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::INFO:
      case MemgraphCypher::IS:
      case MemgraphCypher::KEY:
      case MemgraphCypher::LIMIT:
      case MemgraphCypher::L_SKIP:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::NODE:
      case MemgraphCypher::NONE:
      case MemgraphCypher::NOT:
      case MemgraphCypher::ON:
      case MemgraphCypher::OPTIONAL:
      case MemgraphCypher::OR:
      case MemgraphCypher::ORDER:
      case MemgraphCypher::PROCEDURE:
      case MemgraphCypher::PROFILE:
      case MemgraphCypher::QUERY:
      case MemgraphCypher::REDUCE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::RETURN:
      case MemgraphCypher::SET:
      case MemgraphCypher::SHOW:
      case MemgraphCypher::SINGLE:
      case MemgraphCypher::STARTS:
      case MemgraphCypher::STORAGE:
      case MemgraphCypher::THEN:
      case MemgraphCypher::TRUE:
      case MemgraphCypher::TT:
      case MemgraphCypher::UNION:
      case MemgraphCypher::UNIQUE:
      case MemgraphCypher::UNWIND:
      case MemgraphCypher::WHEN:
      case MemgraphCypher::WHERE:
      case MemgraphCypher::WITH:
      case MemgraphCypher::WSHORTEST:
      case MemgraphCypher::XOR:
      case MemgraphCypher::YIELD:
      case MemgraphCypher::UnescapedSymbolicName:
      case MemgraphCypher::EscapedSymbolicName: {
        enterOuterAlt(_localctx, 1);
        setState(1292);
        variable();
        setState(1293);
        match(MemgraphCypher::EQ);
        setState(1294);
        anonymousPatternPart();
        break;
      }

      case MemgraphCypher::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(1296);
        anonymousPatternPart();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnonymousPatternPartContext ------------------------------------------------------------------

MemgraphCypher::AnonymousPatternPartContext::AnonymousPatternPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::PatternElementContext* MemgraphCypher::AnonymousPatternPartContext::patternElement() {
  return getRuleContext<MemgraphCypher::PatternElementContext>(0);
}


size_t MemgraphCypher::AnonymousPatternPartContext::getRuleIndex() const {
  return MemgraphCypher::RuleAnonymousPatternPart;
}

void MemgraphCypher::AnonymousPatternPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnonymousPatternPart(this);
}

void MemgraphCypher::AnonymousPatternPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnonymousPatternPart(this);
}


antlrcpp::Any MemgraphCypher::AnonymousPatternPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitAnonymousPatternPart(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::AnonymousPatternPartContext* MemgraphCypher::anonymousPatternPart() {
  AnonymousPatternPartContext *_localctx = _tracker.createInstance<AnonymousPatternPartContext>(_ctx, getState());
  enterRule(_localctx, 252, MemgraphCypher::RuleAnonymousPatternPart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1299);
    patternElement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternElementContext ------------------------------------------------------------------

MemgraphCypher::PatternElementContext::PatternElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::NodePatternContext* MemgraphCypher::PatternElementContext::nodePattern() {
  return getRuleContext<MemgraphCypher::NodePatternContext>(0);
}

std::vector<MemgraphCypher::PatternElementChainContext *> MemgraphCypher::PatternElementContext::patternElementChain() {
  return getRuleContexts<MemgraphCypher::PatternElementChainContext>();
}

MemgraphCypher::PatternElementChainContext* MemgraphCypher::PatternElementContext::patternElementChain(size_t i) {
  return getRuleContext<MemgraphCypher::PatternElementChainContext>(i);
}

tree::TerminalNode* MemgraphCypher::PatternElementContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

MemgraphCypher::PatternElementContext* MemgraphCypher::PatternElementContext::patternElement() {
  return getRuleContext<MemgraphCypher::PatternElementContext>(0);
}

tree::TerminalNode* MemgraphCypher::PatternElementContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}


size_t MemgraphCypher::PatternElementContext::getRuleIndex() const {
  return MemgraphCypher::RulePatternElement;
}

void MemgraphCypher::PatternElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternElement(this);
}

void MemgraphCypher::PatternElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternElement(this);
}


antlrcpp::Any MemgraphCypher::PatternElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPatternElement(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PatternElementContext* MemgraphCypher::patternElement() {
  PatternElementContext *_localctx = _tracker.createInstance<PatternElementContext>(_ctx, getState());
  enterRule(_localctx, 254, MemgraphCypher::RulePatternElement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1312);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1301);
      nodePattern();
      setState(1305);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 105) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 105)) & ((1ULL << (MemgraphCypher::LT - 105))
        | (1ULL << (MemgraphCypher::MINUS - 105))
        | (1ULL << (MemgraphCypher::LeftArrowHeadPart - 105))
        | (1ULL << (MemgraphCypher::DashPart - 105)))) != 0)) {
        setState(1302);
        patternElementChain();
        setState(1307);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1308);
      match(MemgraphCypher::LPAREN);
      setState(1309);
      patternElement();
      setState(1310);
      match(MemgraphCypher::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodePatternContext ------------------------------------------------------------------

MemgraphCypher::NodePatternContext::NodePatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::NodePatternContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::NodePatternContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}

MemgraphCypher::VariableContext* MemgraphCypher::NodePatternContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

MemgraphCypher::NodeLabelsContext* MemgraphCypher::NodePatternContext::nodeLabels() {
  return getRuleContext<MemgraphCypher::NodeLabelsContext>(0);
}

MemgraphCypher::PropertiesContext* MemgraphCypher::NodePatternContext::properties() {
  return getRuleContext<MemgraphCypher::PropertiesContext>(0);
}


size_t MemgraphCypher::NodePatternContext::getRuleIndex() const {
  return MemgraphCypher::RuleNodePattern;
}

void MemgraphCypher::NodePatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodePattern(this);
}

void MemgraphCypher::NodePatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodePattern(this);
}


antlrcpp::Any MemgraphCypher::NodePatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitNodePattern(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::NodePatternContext* MemgraphCypher::nodePattern() {
  NodePatternContext *_localctx = _tracker.createInstance<NodePatternContext>(_ctx, getState());
  enterRule(_localctx, 256, MemgraphCypher::RuleNodePattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1314);
    match(MemgraphCypher::LPAREN);
    setState(1316);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1315);
      variable();
    }
    setState(1319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::COLON) {
      setState(1318);
      nodeLabels();
    }
    setState(1322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::LBRACE

    || _la == MemgraphCypher::DOLLAR) {
      setState(1321);
      properties();
    }
    setState(1324);
    match(MemgraphCypher::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternElementChainContext ------------------------------------------------------------------

MemgraphCypher::PatternElementChainContext::PatternElementChainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::RelationshipPatternContext* MemgraphCypher::PatternElementChainContext::relationshipPattern() {
  return getRuleContext<MemgraphCypher::RelationshipPatternContext>(0);
}

MemgraphCypher::NodePatternContext* MemgraphCypher::PatternElementChainContext::nodePattern() {
  return getRuleContext<MemgraphCypher::NodePatternContext>(0);
}


size_t MemgraphCypher::PatternElementChainContext::getRuleIndex() const {
  return MemgraphCypher::RulePatternElementChain;
}

void MemgraphCypher::PatternElementChainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternElementChain(this);
}

void MemgraphCypher::PatternElementChainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternElementChain(this);
}


antlrcpp::Any MemgraphCypher::PatternElementChainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPatternElementChain(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PatternElementChainContext* MemgraphCypher::patternElementChain() {
  PatternElementChainContext *_localctx = _tracker.createInstance<PatternElementChainContext>(_ctx, getState());
  enterRule(_localctx, 258, MemgraphCypher::RulePatternElementChain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1326);
    relationshipPattern();
    setState(1327);
    nodePattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipPatternContext ------------------------------------------------------------------

MemgraphCypher::RelationshipPatternContext::RelationshipPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LeftArrowHeadContext* MemgraphCypher::RelationshipPatternContext::leftArrowHead() {
  return getRuleContext<MemgraphCypher::LeftArrowHeadContext>(0);
}

std::vector<MemgraphCypher::DashContext *> MemgraphCypher::RelationshipPatternContext::dash() {
  return getRuleContexts<MemgraphCypher::DashContext>();
}

MemgraphCypher::DashContext* MemgraphCypher::RelationshipPatternContext::dash(size_t i) {
  return getRuleContext<MemgraphCypher::DashContext>(i);
}

MemgraphCypher::RightArrowHeadContext* MemgraphCypher::RelationshipPatternContext::rightArrowHead() {
  return getRuleContext<MemgraphCypher::RightArrowHeadContext>(0);
}

MemgraphCypher::RelationshipDetailContext* MemgraphCypher::RelationshipPatternContext::relationshipDetail() {
  return getRuleContext<MemgraphCypher::RelationshipDetailContext>(0);
}


size_t MemgraphCypher::RelationshipPatternContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelationshipPattern;
}

void MemgraphCypher::RelationshipPatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationshipPattern(this);
}

void MemgraphCypher::RelationshipPatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationshipPattern(this);
}


antlrcpp::Any MemgraphCypher::RelationshipPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipPattern(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelationshipPatternContext* MemgraphCypher::relationshipPattern() {
  RelationshipPatternContext *_localctx = _tracker.createInstance<RelationshipPatternContext>(_ctx, getState());
  enterRule(_localctx, 260, MemgraphCypher::RuleRelationshipPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1329);
      leftArrowHead();
      setState(1330);
      dash();
      setState(1332);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LBRACK) {
        setState(1331);
        relationshipDetail();
      }
      setState(1334);
      dash();
      setState(1335);
      rightArrowHead();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1337);
      leftArrowHead();
      setState(1338);
      dash();
      setState(1340);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LBRACK) {
        setState(1339);
        relationshipDetail();
      }
      setState(1342);
      dash();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1344);
      dash();
      setState(1346);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LBRACK) {
        setState(1345);
        relationshipDetail();
      }
      setState(1348);
      dash();
      setState(1349);
      rightArrowHead();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1351);
      dash();
      setState(1353);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LBRACK) {
        setState(1352);
        relationshipDetail();
      }
      setState(1355);
      dash();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LeftArrowHeadContext ------------------------------------------------------------------

MemgraphCypher::LeftArrowHeadContext::LeftArrowHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::LeftArrowHeadContext::LT() {
  return getToken(MemgraphCypher::LT, 0);
}

tree::TerminalNode* MemgraphCypher::LeftArrowHeadContext::LeftArrowHeadPart() {
  return getToken(MemgraphCypher::LeftArrowHeadPart, 0);
}


size_t MemgraphCypher::LeftArrowHeadContext::getRuleIndex() const {
  return MemgraphCypher::RuleLeftArrowHead;
}

void MemgraphCypher::LeftArrowHeadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftArrowHead(this);
}

void MemgraphCypher::LeftArrowHeadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftArrowHead(this);
}


antlrcpp::Any MemgraphCypher::LeftArrowHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLeftArrowHead(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LeftArrowHeadContext* MemgraphCypher::leftArrowHead() {
  LeftArrowHeadContext *_localctx = _tracker.createInstance<LeftArrowHeadContext>(_ctx, getState());
  enterRule(_localctx, 262, MemgraphCypher::RuleLeftArrowHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1359);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::LT

    || _la == MemgraphCypher::LeftArrowHeadPart)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RightArrowHeadContext ------------------------------------------------------------------

MemgraphCypher::RightArrowHeadContext::RightArrowHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RightArrowHeadContext::GT() {
  return getToken(MemgraphCypher::GT, 0);
}

tree::TerminalNode* MemgraphCypher::RightArrowHeadContext::RightArrowHeadPart() {
  return getToken(MemgraphCypher::RightArrowHeadPart, 0);
}


size_t MemgraphCypher::RightArrowHeadContext::getRuleIndex() const {
  return MemgraphCypher::RuleRightArrowHead;
}

void MemgraphCypher::RightArrowHeadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightArrowHead(this);
}

void MemgraphCypher::RightArrowHeadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightArrowHead(this);
}


antlrcpp::Any MemgraphCypher::RightArrowHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRightArrowHead(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RightArrowHeadContext* MemgraphCypher::rightArrowHead() {
  RightArrowHeadContext *_localctx = _tracker.createInstance<RightArrowHeadContext>(_ctx, getState());
  enterRule(_localctx, 264, MemgraphCypher::RuleRightArrowHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1361);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::GT

    || _la == MemgraphCypher::RightArrowHeadPart)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DashContext ------------------------------------------------------------------

MemgraphCypher::DashContext::DashContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DashContext::MINUS() {
  return getToken(MemgraphCypher::MINUS, 0);
}

tree::TerminalNode* MemgraphCypher::DashContext::DashPart() {
  return getToken(MemgraphCypher::DashPart, 0);
}


size_t MemgraphCypher::DashContext::getRuleIndex() const {
  return MemgraphCypher::RuleDash;
}

void MemgraphCypher::DashContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDash(this);
}

void MemgraphCypher::DashContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDash(this);
}


antlrcpp::Any MemgraphCypher::DashContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDash(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DashContext* MemgraphCypher::dash() {
  DashContext *_localctx = _tracker.createInstance<DashContext>(_ctx, getState());
  enterRule(_localctx, 266, MemgraphCypher::RuleDash);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1363);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::MINUS

    || _la == MemgraphCypher::DashPart)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipDetailContext ------------------------------------------------------------------

MemgraphCypher::RelationshipDetailContext::RelationshipDetailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RelationshipDetailContext::LBRACK() {
  return getToken(MemgraphCypher::LBRACK, 0);
}

std::vector<MemgraphCypher::PropertiesContext *> MemgraphCypher::RelationshipDetailContext::properties() {
  return getRuleContexts<MemgraphCypher::PropertiesContext>();
}

MemgraphCypher::PropertiesContext* MemgraphCypher::RelationshipDetailContext::properties(size_t i) {
  return getRuleContext<MemgraphCypher::PropertiesContext>(i);
}

tree::TerminalNode* MemgraphCypher::RelationshipDetailContext::RBRACK() {
  return getToken(MemgraphCypher::RBRACK, 0);
}

MemgraphCypher::RelationshipTypesContext* MemgraphCypher::RelationshipDetailContext::relationshipTypes() {
  return getRuleContext<MemgraphCypher::RelationshipTypesContext>(0);
}

MemgraphCypher::VariableExpansionContext* MemgraphCypher::RelationshipDetailContext::variableExpansion() {
  return getRuleContext<MemgraphCypher::VariableExpansionContext>(0);
}

std::vector<MemgraphCypher::VariableContext *> MemgraphCypher::RelationshipDetailContext::variable() {
  return getRuleContexts<MemgraphCypher::VariableContext>();
}

MemgraphCypher::VariableContext* MemgraphCypher::RelationshipDetailContext::variable(size_t i) {
  return getRuleContext<MemgraphCypher::VariableContext>(i);
}

std::vector<MemgraphCypher::RelationshipLambdaContext *> MemgraphCypher::RelationshipDetailContext::relationshipLambda() {
  return getRuleContexts<MemgraphCypher::RelationshipLambdaContext>();
}

MemgraphCypher::RelationshipLambdaContext* MemgraphCypher::RelationshipDetailContext::relationshipLambda(size_t i) {
  return getRuleContext<MemgraphCypher::RelationshipLambdaContext>(i);
}


size_t MemgraphCypher::RelationshipDetailContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelationshipDetail;
}

void MemgraphCypher::RelationshipDetailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationshipDetail(this);
}

void MemgraphCypher::RelationshipDetailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationshipDetail(this);
}


antlrcpp::Any MemgraphCypher::RelationshipDetailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipDetail(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelationshipDetailContext* MemgraphCypher::relationshipDetail() {
  RelationshipDetailContext *_localctx = _tracker.createInstance<RelationshipDetailContext>(_ctx, getState());
  enterRule(_localctx, 268, MemgraphCypher::RuleRelationshipDetail);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1422);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1365);
      match(MemgraphCypher::LBRACK);
      setState(1367);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1366);
        dynamic_cast<RelationshipDetailContext *>(_localctx)->name = variable();
      }
      setState(1370);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::COLON) {
        setState(1369);
        relationshipTypes();
      }
      setState(1373);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::ASTERISK) {
        setState(1372);
        variableExpansion();
      }
      setState(1375);
      properties();
      setState(1376);
      match(MemgraphCypher::RBRACK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1378);
      match(MemgraphCypher::LBRACK);
      setState(1380);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1379);
        dynamic_cast<RelationshipDetailContext *>(_localctx)->name = variable();
      }
      setState(1383);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::COLON) {
        setState(1382);
        relationshipTypes();
      }
      setState(1386);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::ASTERISK) {
        setState(1385);
        variableExpansion();
      }
      setState(1388);
      relationshipLambda();
      setState(1390);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1389);
        dynamic_cast<RelationshipDetailContext *>(_localctx)->total_weight = variable();
      }
      setState(1393);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LPAREN) {
        setState(1392);
        relationshipLambda();
      }
      setState(1395);
      match(MemgraphCypher::RBRACK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1397);
      match(MemgraphCypher::LBRACK);
      setState(1399);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1398);
        dynamic_cast<RelationshipDetailContext *>(_localctx)->name = variable();
      }
      setState(1402);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::COLON) {
        setState(1401);
        relationshipTypes();
      }
      setState(1405);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::ASTERISK) {
        setState(1404);
        variableExpansion();
      }
      setState(1410);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::LBRACE

      || _la == MemgraphCypher::DOLLAR) {
        setState(1407);
        properties();
        setState(1412);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1416);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
      case 1: {
        setState(1413);
        relationshipLambda();
        setState(1414);
        dynamic_cast<RelationshipDetailContext *>(_localctx)->total_weight = variable();
        break;
      }

      default:
        break;
      }
      setState(1419);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::LPAREN) {
        setState(1418);
        relationshipLambda();
      }
      setState(1421);
      match(MemgraphCypher::RBRACK);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipLambdaContext ------------------------------------------------------------------

MemgraphCypher::RelationshipLambdaContext::RelationshipLambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::RelationshipLambdaContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::RelationshipLambdaContext::COMMA() {
  return getToken(MemgraphCypher::COMMA, 0);
}

tree::TerminalNode* MemgraphCypher::RelationshipLambdaContext::PIPE() {
  return getToken(MemgraphCypher::PIPE, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::RelationshipLambdaContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::RelationshipLambdaContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}

std::vector<MemgraphCypher::VariableContext *> MemgraphCypher::RelationshipLambdaContext::variable() {
  return getRuleContexts<MemgraphCypher::VariableContext>();
}

MemgraphCypher::VariableContext* MemgraphCypher::RelationshipLambdaContext::variable(size_t i) {
  return getRuleContext<MemgraphCypher::VariableContext>(i);
}


size_t MemgraphCypher::RelationshipLambdaContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelationshipLambda;
}

void MemgraphCypher::RelationshipLambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationshipLambda(this);
}

void MemgraphCypher::RelationshipLambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationshipLambda(this);
}


antlrcpp::Any MemgraphCypher::RelationshipLambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipLambda(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelationshipLambdaContext* MemgraphCypher::relationshipLambda() {
  RelationshipLambdaContext *_localctx = _tracker.createInstance<RelationshipLambdaContext>(_ctx, getState());
  enterRule(_localctx, 270, MemgraphCypher::RuleRelationshipLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1424);
    match(MemgraphCypher::LPAREN);
    setState(1425);
    dynamic_cast<RelationshipLambdaContext *>(_localctx)->traversed_edge = variable();
    setState(1426);
    match(MemgraphCypher::COMMA);
    setState(1427);
    dynamic_cast<RelationshipLambdaContext *>(_localctx)->traversed_node = variable();
    setState(1428);
    match(MemgraphCypher::PIPE);
    setState(1429);
    expression();
    setState(1430);
    match(MemgraphCypher::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableExpansionContext ------------------------------------------------------------------

MemgraphCypher::VariableExpansionContext::VariableExpansionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::VariableExpansionContext::ASTERISK() {
  return getToken(MemgraphCypher::ASTERISK, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::VariableExpansionContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::VariableExpansionContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

tree::TerminalNode* MemgraphCypher::VariableExpansionContext::DOTS() {
  return getToken(MemgraphCypher::DOTS, 0);
}

tree::TerminalNode* MemgraphCypher::VariableExpansionContext::BFS() {
  return getToken(MemgraphCypher::BFS, 0);
}

tree::TerminalNode* MemgraphCypher::VariableExpansionContext::WSHORTEST() {
  return getToken(MemgraphCypher::WSHORTEST, 0);
}


size_t MemgraphCypher::VariableExpansionContext::getRuleIndex() const {
  return MemgraphCypher::RuleVariableExpansion;
}

void MemgraphCypher::VariableExpansionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableExpansion(this);
}

void MemgraphCypher::VariableExpansionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableExpansion(this);
}


antlrcpp::Any MemgraphCypher::VariableExpansionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitVariableExpansion(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::VariableExpansionContext* MemgraphCypher::variableExpansion() {
  VariableExpansionContext *_localctx = _tracker.createInstance<VariableExpansionContext>(_ctx, getState());
  enterRule(_localctx, 272, MemgraphCypher::RuleVariableExpansion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1432);
    match(MemgraphCypher::ASTERISK);
    setState(1434);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
    case 1: {
      setState(1433);
      _la = _input->LA(1);
      if (!(_la == MemgraphCypher::BFS

      || _la == MemgraphCypher::WSHORTEST)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
    setState(1437);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
    case 1: {
      setState(1436);
      expression();
      break;
    }

    default:
      break;
    }
    setState(1443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::DOTS) {
      setState(1439);
      match(MemgraphCypher::DOTS);
      setState(1441);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
      case 1: {
        setState(1440);
        expression();
        break;
      }

      default:
        break;
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

MemgraphCypher::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::MapLiteralContext* MemgraphCypher::PropertiesContext::mapLiteral() {
  return getRuleContext<MemgraphCypher::MapLiteralContext>(0);
}

MemgraphCypher::ParameterContext* MemgraphCypher::PropertiesContext::parameter() {
  return getRuleContext<MemgraphCypher::ParameterContext>(0);
}


size_t MemgraphCypher::PropertiesContext::getRuleIndex() const {
  return MemgraphCypher::RuleProperties;
}

void MemgraphCypher::PropertiesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperties(this);
}

void MemgraphCypher::PropertiesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperties(this);
}


antlrcpp::Any MemgraphCypher::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PropertiesContext* MemgraphCypher::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 274, MemgraphCypher::RuleProperties);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1447);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(1445);
        mapLiteral();
        break;
      }

      case MemgraphCypher::DOLLAR: {
        enterOuterAlt(_localctx, 2);
        setState(1446);
        parameter();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipTypesContext ------------------------------------------------------------------

MemgraphCypher::RelationshipTypesContext::RelationshipTypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MemgraphCypher::RelationshipTypesContext::COLON() {
  return getTokens(MemgraphCypher::COLON);
}

tree::TerminalNode* MemgraphCypher::RelationshipTypesContext::COLON(size_t i) {
  return getToken(MemgraphCypher::COLON, i);
}

std::vector<MemgraphCypher::RelTypeNameContext *> MemgraphCypher::RelationshipTypesContext::relTypeName() {
  return getRuleContexts<MemgraphCypher::RelTypeNameContext>();
}

MemgraphCypher::RelTypeNameContext* MemgraphCypher::RelationshipTypesContext::relTypeName(size_t i) {
  return getRuleContext<MemgraphCypher::RelTypeNameContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::RelationshipTypesContext::PIPE() {
  return getTokens(MemgraphCypher::PIPE);
}

tree::TerminalNode* MemgraphCypher::RelationshipTypesContext::PIPE(size_t i) {
  return getToken(MemgraphCypher::PIPE, i);
}


size_t MemgraphCypher::RelationshipTypesContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelationshipTypes;
}

void MemgraphCypher::RelationshipTypesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationshipTypes(this);
}

void MemgraphCypher::RelationshipTypesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationshipTypes(this);
}


antlrcpp::Any MemgraphCypher::RelationshipTypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipTypes(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelationshipTypesContext* MemgraphCypher::relationshipTypes() {
  RelationshipTypesContext *_localctx = _tracker.createInstance<RelationshipTypesContext>(_ctx, getState());
  enterRule(_localctx, 276, MemgraphCypher::RuleRelationshipTypes);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1449);
    match(MemgraphCypher::COLON);
    setState(1450);
    relTypeName();
    setState(1458);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::PIPE) {
      setState(1451);
      match(MemgraphCypher::PIPE);
      setState(1453);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MemgraphCypher::COLON) {
        setState(1452);
        match(MemgraphCypher::COLON);
      }
      setState(1455);
      relTypeName();
      setState(1460);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeLabelsContext ------------------------------------------------------------------

MemgraphCypher::NodeLabelsContext::NodeLabelsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::NodeLabelContext *> MemgraphCypher::NodeLabelsContext::nodeLabel() {
  return getRuleContexts<MemgraphCypher::NodeLabelContext>();
}

MemgraphCypher::NodeLabelContext* MemgraphCypher::NodeLabelsContext::nodeLabel(size_t i) {
  return getRuleContext<MemgraphCypher::NodeLabelContext>(i);
}


size_t MemgraphCypher::NodeLabelsContext::getRuleIndex() const {
  return MemgraphCypher::RuleNodeLabels;
}

void MemgraphCypher::NodeLabelsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodeLabels(this);
}

void MemgraphCypher::NodeLabelsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodeLabels(this);
}


antlrcpp::Any MemgraphCypher::NodeLabelsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitNodeLabels(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::NodeLabelsContext* MemgraphCypher::nodeLabels() {
  NodeLabelsContext *_localctx = _tracker.createInstance<NodeLabelsContext>(_ctx, getState());
  enterRule(_localctx, 278, MemgraphCypher::RuleNodeLabels);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1461);
    nodeLabel();
    setState(1465);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::COLON) {
      setState(1462);
      nodeLabel();
      setState(1467);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeLabelContext ------------------------------------------------------------------

MemgraphCypher::NodeLabelContext::NodeLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::NodeLabelContext::COLON() {
  return getToken(MemgraphCypher::COLON, 0);
}

MemgraphCypher::LabelNameContext* MemgraphCypher::NodeLabelContext::labelName() {
  return getRuleContext<MemgraphCypher::LabelNameContext>(0);
}


size_t MemgraphCypher::NodeLabelContext::getRuleIndex() const {
  return MemgraphCypher::RuleNodeLabel;
}

void MemgraphCypher::NodeLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodeLabel(this);
}

void MemgraphCypher::NodeLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodeLabel(this);
}


antlrcpp::Any MemgraphCypher::NodeLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitNodeLabel(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::NodeLabelContext* MemgraphCypher::nodeLabel() {
  NodeLabelContext *_localctx = _tracker.createInstance<NodeLabelContext>(_ctx, getState());
  enterRule(_localctx, 280, MemgraphCypher::RuleNodeLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1468);
    match(MemgraphCypher::COLON);
    setState(1469);
    labelName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelNameContext ------------------------------------------------------------------

MemgraphCypher::LabelNameContext::LabelNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::LabelNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::LabelNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleLabelName;
}

void MemgraphCypher::LabelNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelName(this);
}

void MemgraphCypher::LabelNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelName(this);
}


antlrcpp::Any MemgraphCypher::LabelNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLabelName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LabelNameContext* MemgraphCypher::labelName() {
  LabelNameContext *_localctx = _tracker.createInstance<LabelNameContext>(_ctx, getState());
  enterRule(_localctx, 282, MemgraphCypher::RuleLabelName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1471);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelTypeNameContext ------------------------------------------------------------------

MemgraphCypher::RelTypeNameContext::RelTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::RelTypeNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::RelTypeNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelTypeName;
}

void MemgraphCypher::RelTypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelTypeName(this);
}

void MemgraphCypher::RelTypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelTypeName(this);
}


antlrcpp::Any MemgraphCypher::RelTypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelTypeName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelTypeNameContext* MemgraphCypher::relTypeName() {
  RelTypeNameContext *_localctx = _tracker.createInstance<RelTypeNameContext>(_ctx, getState());
  enterRule(_localctx, 284, MemgraphCypher::RuleRelTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1473);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MemgraphCypher::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression12Context* MemgraphCypher::ExpressionContext::expression12() {
  return getRuleContext<MemgraphCypher::Expression12Context>(0);
}


size_t MemgraphCypher::ExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleExpression;
}

void MemgraphCypher::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void MemgraphCypher::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any MemgraphCypher::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 286, MemgraphCypher::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1475);
    expression12();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression12Context ------------------------------------------------------------------

MemgraphCypher::Expression12Context::Expression12Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression11Context *> MemgraphCypher::Expression12Context::expression11() {
  return getRuleContexts<MemgraphCypher::Expression11Context>();
}

MemgraphCypher::Expression11Context* MemgraphCypher::Expression12Context::expression11(size_t i) {
  return getRuleContext<MemgraphCypher::Expression11Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression12Context::OR() {
  return getTokens(MemgraphCypher::OR);
}

tree::TerminalNode* MemgraphCypher::Expression12Context::OR(size_t i) {
  return getToken(MemgraphCypher::OR, i);
}


size_t MemgraphCypher::Expression12Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression12;
}

void MemgraphCypher::Expression12Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression12(this);
}

void MemgraphCypher::Expression12Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression12(this);
}


antlrcpp::Any MemgraphCypher::Expression12Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression12(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression12Context* MemgraphCypher::expression12() {
  Expression12Context *_localctx = _tracker.createInstance<Expression12Context>(_ctx, getState());
  enterRule(_localctx, 288, MemgraphCypher::RuleExpression12);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1477);
    expression11();
    setState(1482);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::OR) {
      setState(1478);
      match(MemgraphCypher::OR);
      setState(1479);
      expression11();
      setState(1484);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression11Context ------------------------------------------------------------------

MemgraphCypher::Expression11Context::Expression11Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression10Context *> MemgraphCypher::Expression11Context::expression10() {
  return getRuleContexts<MemgraphCypher::Expression10Context>();
}

MemgraphCypher::Expression10Context* MemgraphCypher::Expression11Context::expression10(size_t i) {
  return getRuleContext<MemgraphCypher::Expression10Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression11Context::XOR() {
  return getTokens(MemgraphCypher::XOR);
}

tree::TerminalNode* MemgraphCypher::Expression11Context::XOR(size_t i) {
  return getToken(MemgraphCypher::XOR, i);
}


size_t MemgraphCypher::Expression11Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression11;
}

void MemgraphCypher::Expression11Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression11(this);
}

void MemgraphCypher::Expression11Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression11(this);
}


antlrcpp::Any MemgraphCypher::Expression11Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression11(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression11Context* MemgraphCypher::expression11() {
  Expression11Context *_localctx = _tracker.createInstance<Expression11Context>(_ctx, getState());
  enterRule(_localctx, 290, MemgraphCypher::RuleExpression11);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1485);
    expression10();
    setState(1490);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::XOR) {
      setState(1486);
      match(MemgraphCypher::XOR);
      setState(1487);
      expression10();
      setState(1492);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression10Context ------------------------------------------------------------------

MemgraphCypher::Expression10Context::Expression10Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression9Context *> MemgraphCypher::Expression10Context::expression9() {
  return getRuleContexts<MemgraphCypher::Expression9Context>();
}

MemgraphCypher::Expression9Context* MemgraphCypher::Expression10Context::expression9(size_t i) {
  return getRuleContext<MemgraphCypher::Expression9Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression10Context::AND() {
  return getTokens(MemgraphCypher::AND);
}

tree::TerminalNode* MemgraphCypher::Expression10Context::AND(size_t i) {
  return getToken(MemgraphCypher::AND, i);
}


size_t MemgraphCypher::Expression10Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression10;
}

void MemgraphCypher::Expression10Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression10(this);
}

void MemgraphCypher::Expression10Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression10(this);
}


antlrcpp::Any MemgraphCypher::Expression10Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression10(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression10Context* MemgraphCypher::expression10() {
  Expression10Context *_localctx = _tracker.createInstance<Expression10Context>(_ctx, getState());
  enterRule(_localctx, 292, MemgraphCypher::RuleExpression10);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1493);
    expression9();
    setState(1498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::AND) {
      setState(1494);
      match(MemgraphCypher::AND);
      setState(1495);
      expression9();
      setState(1500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression9Context ------------------------------------------------------------------

MemgraphCypher::Expression9Context::Expression9Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression8Context* MemgraphCypher::Expression9Context::expression8() {
  return getRuleContext<MemgraphCypher::Expression8Context>(0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression9Context::NOT() {
  return getTokens(MemgraphCypher::NOT);
}

tree::TerminalNode* MemgraphCypher::Expression9Context::NOT(size_t i) {
  return getToken(MemgraphCypher::NOT, i);
}


size_t MemgraphCypher::Expression9Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression9;
}

void MemgraphCypher::Expression9Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression9(this);
}

void MemgraphCypher::Expression9Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression9(this);
}


antlrcpp::Any MemgraphCypher::Expression9Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression9(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression9Context* MemgraphCypher::expression9() {
  Expression9Context *_localctx = _tracker.createInstance<Expression9Context>(_ctx, getState());
  enterRule(_localctx, 294, MemgraphCypher::RuleExpression9);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1504);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1501);
        match(MemgraphCypher::NOT); 
      }
      setState(1506);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx);
    }
    setState(1507);
    expression8();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression8Context ------------------------------------------------------------------

MemgraphCypher::Expression8Context::Expression8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression7Context* MemgraphCypher::Expression8Context::expression7() {
  return getRuleContext<MemgraphCypher::Expression7Context>(0);
}

std::vector<MemgraphCypher::PartialComparisonExpressionContext *> MemgraphCypher::Expression8Context::partialComparisonExpression() {
  return getRuleContexts<MemgraphCypher::PartialComparisonExpressionContext>();
}

MemgraphCypher::PartialComparisonExpressionContext* MemgraphCypher::Expression8Context::partialComparisonExpression(size_t i) {
  return getRuleContext<MemgraphCypher::PartialComparisonExpressionContext>(i);
}


size_t MemgraphCypher::Expression8Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression8;
}

void MemgraphCypher::Expression8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression8(this);
}

void MemgraphCypher::Expression8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression8(this);
}


antlrcpp::Any MemgraphCypher::Expression8Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression8(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression8Context* MemgraphCypher::expression8() {
  Expression8Context *_localctx = _tracker.createInstance<Expression8Context>(_ctx, getState());
  enterRule(_localctx, 296, MemgraphCypher::RuleExpression8);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1509);
    expression7();
    setState(1513);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 104) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 104)) & ((1ULL << (MemgraphCypher::EQ - 104))
      | (1ULL << (MemgraphCypher::LT - 104))
      | (1ULL << (MemgraphCypher::GT - 104))
      | (1ULL << (MemgraphCypher::LTE - 104))
      | (1ULL << (MemgraphCypher::GTE - 104))
      | (1ULL << (MemgraphCypher::NEQ1 - 104))
      | (1ULL << (MemgraphCypher::NEQ2 - 104)))) != 0)) {
      setState(1510);
      partialComparisonExpression();
      setState(1515);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression7Context ------------------------------------------------------------------

MemgraphCypher::Expression7Context::Expression7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression6Context *> MemgraphCypher::Expression7Context::expression6() {
  return getRuleContexts<MemgraphCypher::Expression6Context>();
}

MemgraphCypher::Expression6Context* MemgraphCypher::Expression7Context::expression6(size_t i) {
  return getRuleContext<MemgraphCypher::Expression6Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression7Context::PLUS() {
  return getTokens(MemgraphCypher::PLUS);
}

tree::TerminalNode* MemgraphCypher::Expression7Context::PLUS(size_t i) {
  return getToken(MemgraphCypher::PLUS, i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression7Context::MINUS() {
  return getTokens(MemgraphCypher::MINUS);
}

tree::TerminalNode* MemgraphCypher::Expression7Context::MINUS(size_t i) {
  return getToken(MemgraphCypher::MINUS, i);
}


size_t MemgraphCypher::Expression7Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression7;
}

void MemgraphCypher::Expression7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression7(this);
}

void MemgraphCypher::Expression7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression7(this);
}


antlrcpp::Any MemgraphCypher::Expression7Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression7(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression7Context* MemgraphCypher::expression7() {
  Expression7Context *_localctx = _tracker.createInstance<Expression7Context>(_ctx, getState());
  enterRule(_localctx, 298, MemgraphCypher::RuleExpression7);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1516);
    expression6();
    setState(1523);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::PLUS

    || _la == MemgraphCypher::MINUS) {
      setState(1521);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MemgraphCypher::PLUS: {
          setState(1517);
          match(MemgraphCypher::PLUS);
          setState(1518);
          expression6();
          break;
        }

        case MemgraphCypher::MINUS: {
          setState(1519);
          match(MemgraphCypher::MINUS);
          setState(1520);
          expression6();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1525);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression6Context ------------------------------------------------------------------

MemgraphCypher::Expression6Context::Expression6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression5Context *> MemgraphCypher::Expression6Context::expression5() {
  return getRuleContexts<MemgraphCypher::Expression5Context>();
}

MemgraphCypher::Expression5Context* MemgraphCypher::Expression6Context::expression5(size_t i) {
  return getRuleContext<MemgraphCypher::Expression5Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression6Context::ASTERISK() {
  return getTokens(MemgraphCypher::ASTERISK);
}

tree::TerminalNode* MemgraphCypher::Expression6Context::ASTERISK(size_t i) {
  return getToken(MemgraphCypher::ASTERISK, i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression6Context::SLASH() {
  return getTokens(MemgraphCypher::SLASH);
}

tree::TerminalNode* MemgraphCypher::Expression6Context::SLASH(size_t i) {
  return getToken(MemgraphCypher::SLASH, i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression6Context::PERCENT() {
  return getTokens(MemgraphCypher::PERCENT);
}

tree::TerminalNode* MemgraphCypher::Expression6Context::PERCENT(size_t i) {
  return getToken(MemgraphCypher::PERCENT, i);
}


size_t MemgraphCypher::Expression6Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression6;
}

void MemgraphCypher::Expression6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression6(this);
}

void MemgraphCypher::Expression6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression6(this);
}


antlrcpp::Any MemgraphCypher::Expression6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression6(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression6Context* MemgraphCypher::expression6() {
  Expression6Context *_localctx = _tracker.createInstance<Expression6Context>(_ctx, getState());
  enterRule(_localctx, 300, MemgraphCypher::RuleExpression6);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1526);
    expression5();
    setState(1535);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (MemgraphCypher::ASTERISK - 114))
      | (1ULL << (MemgraphCypher::SLASH - 114))
      | (1ULL << (MemgraphCypher::PERCENT - 114)))) != 0)) {
      setState(1533);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MemgraphCypher::ASTERISK: {
          setState(1527);
          match(MemgraphCypher::ASTERISK);
          setState(1528);
          expression5();
          break;
        }

        case MemgraphCypher::SLASH: {
          setState(1529);
          match(MemgraphCypher::SLASH);
          setState(1530);
          expression5();
          break;
        }

        case MemgraphCypher::PERCENT: {
          setState(1531);
          match(MemgraphCypher::PERCENT);
          setState(1532);
          expression5();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1537);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression5Context ------------------------------------------------------------------

MemgraphCypher::Expression5Context::Expression5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MemgraphCypher::Expression4Context *> MemgraphCypher::Expression5Context::expression4() {
  return getRuleContexts<MemgraphCypher::Expression4Context>();
}

MemgraphCypher::Expression4Context* MemgraphCypher::Expression5Context::expression4(size_t i) {
  return getRuleContext<MemgraphCypher::Expression4Context>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression5Context::CARET() {
  return getTokens(MemgraphCypher::CARET);
}

tree::TerminalNode* MemgraphCypher::Expression5Context::CARET(size_t i) {
  return getToken(MemgraphCypher::CARET, i);
}


size_t MemgraphCypher::Expression5Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression5;
}

void MemgraphCypher::Expression5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression5(this);
}

void MemgraphCypher::Expression5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression5(this);
}


antlrcpp::Any MemgraphCypher::Expression5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression5(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression5Context* MemgraphCypher::expression5() {
  Expression5Context *_localctx = _tracker.createInstance<Expression5Context>(_ctx, getState());
  enterRule(_localctx, 302, MemgraphCypher::RuleExpression5);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1538);
    expression4();
    setState(1543);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::CARET) {
      setState(1539);
      match(MemgraphCypher::CARET);
      setState(1540);
      expression4();
      setState(1545);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression4Context ------------------------------------------------------------------

MemgraphCypher::Expression4Context::Expression4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression3aContext* MemgraphCypher::Expression4Context::expression3a() {
  return getRuleContext<MemgraphCypher::Expression3aContext>(0);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression4Context::PLUS() {
  return getTokens(MemgraphCypher::PLUS);
}

tree::TerminalNode* MemgraphCypher::Expression4Context::PLUS(size_t i) {
  return getToken(MemgraphCypher::PLUS, i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::Expression4Context::MINUS() {
  return getTokens(MemgraphCypher::MINUS);
}

tree::TerminalNode* MemgraphCypher::Expression4Context::MINUS(size_t i) {
  return getToken(MemgraphCypher::MINUS, i);
}


size_t MemgraphCypher::Expression4Context::getRuleIndex() const {
  return MemgraphCypher::RuleExpression4;
}

void MemgraphCypher::Expression4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression4(this);
}

void MemgraphCypher::Expression4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression4(this);
}


antlrcpp::Any MemgraphCypher::Expression4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression4(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression4Context* MemgraphCypher::expression4() {
  Expression4Context *_localctx = _tracker.createInstance<Expression4Context>(_ctx, getState());
  enterRule(_localctx, 304, MemgraphCypher::RuleExpression4);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1549);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::PLUS

    || _la == MemgraphCypher::MINUS) {
      setState(1546);
      _la = _input->LA(1);
      if (!(_la == MemgraphCypher::PLUS

      || _la == MemgraphCypher::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1551);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1552);
    expression3a();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression3aContext ------------------------------------------------------------------

MemgraphCypher::Expression3aContext::Expression3aContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression3bContext* MemgraphCypher::Expression3aContext::expression3b() {
  return getRuleContext<MemgraphCypher::Expression3bContext>(0);
}

std::vector<MemgraphCypher::StringAndNullOperatorsContext *> MemgraphCypher::Expression3aContext::stringAndNullOperators() {
  return getRuleContexts<MemgraphCypher::StringAndNullOperatorsContext>();
}

MemgraphCypher::StringAndNullOperatorsContext* MemgraphCypher::Expression3aContext::stringAndNullOperators(size_t i) {
  return getRuleContext<MemgraphCypher::StringAndNullOperatorsContext>(i);
}


size_t MemgraphCypher::Expression3aContext::getRuleIndex() const {
  return MemgraphCypher::RuleExpression3a;
}

void MemgraphCypher::Expression3aContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression3a(this);
}

void MemgraphCypher::Expression3aContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression3a(this);
}


antlrcpp::Any MemgraphCypher::Expression3aContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression3a(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression3aContext* MemgraphCypher::expression3a() {
  Expression3aContext *_localctx = _tracker.createInstance<Expression3aContext>(_ctx, getState());
  enterRule(_localctx, 306, MemgraphCypher::RuleExpression3a);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1554);
    expression3b();
    setState(1558);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 111) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 111)) & ((1ULL << (MemgraphCypher::SIM - 111))
      | (1ULL << (MemgraphCypher::CONTAINS - 111))
      | (1ULL << (MemgraphCypher::ENDS - 111))
      | (1ULL << (MemgraphCypher::IN - 111))
      | (1ULL << (MemgraphCypher::IS - 111)))) != 0) || _la == MemgraphCypher::STARTS) {
      setState(1555);
      stringAndNullOperators();
      setState(1560);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringAndNullOperatorsContext ------------------------------------------------------------------

MemgraphCypher::StringAndNullOperatorsContext::StringAndNullOperatorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression3bContext* MemgraphCypher::StringAndNullOperatorsContext::expression3b() {
  return getRuleContext<MemgraphCypher::Expression3bContext>(0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::IS() {
  return getToken(MemgraphCypher::IS, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::CYPHERNULL() {
  return getToken(MemgraphCypher::CYPHERNULL, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::NOT() {
  return getToken(MemgraphCypher::NOT, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::SIM() {
  return getToken(MemgraphCypher::SIM, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::IN() {
  return getToken(MemgraphCypher::IN, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::STARTS() {
  return getToken(MemgraphCypher::STARTS, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::ENDS() {
  return getToken(MemgraphCypher::ENDS, 0);
}

tree::TerminalNode* MemgraphCypher::StringAndNullOperatorsContext::CONTAINS() {
  return getToken(MemgraphCypher::CONTAINS, 0);
}


size_t MemgraphCypher::StringAndNullOperatorsContext::getRuleIndex() const {
  return MemgraphCypher::RuleStringAndNullOperators;
}

void MemgraphCypher::StringAndNullOperatorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringAndNullOperators(this);
}

void MemgraphCypher::StringAndNullOperatorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringAndNullOperators(this);
}


antlrcpp::Any MemgraphCypher::StringAndNullOperatorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitStringAndNullOperators(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::StringAndNullOperatorsContext* MemgraphCypher::stringAndNullOperators() {
  StringAndNullOperatorsContext *_localctx = _tracker.createInstance<StringAndNullOperatorsContext>(_ctx, getState());
  enterRule(_localctx, 308, MemgraphCypher::RuleStringAndNullOperators);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1576);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 129, _ctx)) {
    case 1: {
      setState(1568);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MemgraphCypher::SIM: {
          setState(1561);
          match(MemgraphCypher::SIM);
          break;
        }

        case MemgraphCypher::IN: {
          setState(1562);
          match(MemgraphCypher::IN);
          break;
        }

        case MemgraphCypher::STARTS: {
          setState(1563);
          match(MemgraphCypher::STARTS);
          setState(1564);
          match(MemgraphCypher::WITH);
          break;
        }

        case MemgraphCypher::ENDS: {
          setState(1565);
          match(MemgraphCypher::ENDS);
          setState(1566);
          match(MemgraphCypher::WITH);
          break;
        }

        case MemgraphCypher::CONTAINS: {
          setState(1567);
          match(MemgraphCypher::CONTAINS);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1570);
      expression3b();
      break;
    }

    case 2: {
      setState(1571);
      match(MemgraphCypher::IS);
      setState(1572);
      match(MemgraphCypher::CYPHERNULL);
      break;
    }

    case 3: {
      setState(1573);
      match(MemgraphCypher::IS);
      setState(1574);
      match(MemgraphCypher::NOT);
      setState(1575);
      match(MemgraphCypher::CYPHERNULL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression3bContext ------------------------------------------------------------------

MemgraphCypher::Expression3bContext::Expression3bContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression2aContext* MemgraphCypher::Expression3bContext::expression2a() {
  return getRuleContext<MemgraphCypher::Expression2aContext>(0);
}

std::vector<MemgraphCypher::ListIndexingOrSlicingContext *> MemgraphCypher::Expression3bContext::listIndexingOrSlicing() {
  return getRuleContexts<MemgraphCypher::ListIndexingOrSlicingContext>();
}

MemgraphCypher::ListIndexingOrSlicingContext* MemgraphCypher::Expression3bContext::listIndexingOrSlicing(size_t i) {
  return getRuleContext<MemgraphCypher::ListIndexingOrSlicingContext>(i);
}


size_t MemgraphCypher::Expression3bContext::getRuleIndex() const {
  return MemgraphCypher::RuleExpression3b;
}

void MemgraphCypher::Expression3bContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression3b(this);
}

void MemgraphCypher::Expression3bContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression3b(this);
}


antlrcpp::Any MemgraphCypher::Expression3bContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression3b(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression3bContext* MemgraphCypher::expression3b() {
  Expression3bContext *_localctx = _tracker.createInstance<Expression3bContext>(_ctx, getState());
  enterRule(_localctx, 310, MemgraphCypher::RuleExpression3b);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1578);
    expression2a();
    setState(1582);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::LBRACK) {
      setState(1579);
      listIndexingOrSlicing();
      setState(1584);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListIndexingOrSlicingContext ------------------------------------------------------------------

MemgraphCypher::ListIndexingOrSlicingContext::ListIndexingOrSlicingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ListIndexingOrSlicingContext::LBRACK() {
  return getToken(MemgraphCypher::LBRACK, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::ListIndexingOrSlicingContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ListIndexingOrSlicingContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

tree::TerminalNode* MemgraphCypher::ListIndexingOrSlicingContext::RBRACK() {
  return getToken(MemgraphCypher::RBRACK, 0);
}

tree::TerminalNode* MemgraphCypher::ListIndexingOrSlicingContext::DOTS() {
  return getToken(MemgraphCypher::DOTS, 0);
}


size_t MemgraphCypher::ListIndexingOrSlicingContext::getRuleIndex() const {
  return MemgraphCypher::RuleListIndexingOrSlicing;
}

void MemgraphCypher::ListIndexingOrSlicingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListIndexingOrSlicing(this);
}

void MemgraphCypher::ListIndexingOrSlicingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListIndexingOrSlicing(this);
}


antlrcpp::Any MemgraphCypher::ListIndexingOrSlicingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitListIndexingOrSlicing(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ListIndexingOrSlicingContext* MemgraphCypher::listIndexingOrSlicing() {
  ListIndexingOrSlicingContext *_localctx = _tracker.createInstance<ListIndexingOrSlicingContext>(_ctx, getState());
  enterRule(_localctx, 312, MemgraphCypher::RuleListIndexingOrSlicing);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1598);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1585);
      match(MemgraphCypher::LBRACK);
      setState(1586);
      expression();
      setState(1587);
      match(MemgraphCypher::RBRACK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1589);
      match(MemgraphCypher::LBRACK);
      setState(1591);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::LPAREN - 64))
        | (1ULL << (MemgraphCypher::LBRACK - 64))
        | (1ULL << (MemgraphCypher::LBRACE - 64))
        | (1ULL << (MemgraphCypher::DOLLAR - 64))
        | (1ULL << (MemgraphCypher::PLUS - 64))
        | (1ULL << (MemgraphCypher::MINUS - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::COALESCE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::StringLiteral - 192))
        | (1ULL << (MemgraphCypher::DecimalLiteral - 192))
        | (1ULL << (MemgraphCypher::OctalLiteral - 192))
        | (1ULL << (MemgraphCypher::HexadecimalLiteral - 192))
        | (1ULL << (MemgraphCypher::FloatingLiteral - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1590);
        dynamic_cast<ListIndexingOrSlicingContext *>(_localctx)->lower_bound = expression();
      }
      setState(1593);
      match(MemgraphCypher::DOTS);
      setState(1595);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
        | (1ULL << MemgraphCypher::ALTER)
        | (1ULL << MemgraphCypher::ASYNC)
        | (1ULL << MemgraphCypher::AUTH)
        | (1ULL << MemgraphCypher::BAD)
        | (1ULL << MemgraphCypher::BATCH_INTERVAL)
        | (1ULL << MemgraphCypher::BATCH_LIMIT)
        | (1ULL << MemgraphCypher::BATCH_SIZE)
        | (1ULL << MemgraphCypher::BEFORE)
        | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
        | (1ULL << MemgraphCypher::CHECK)
        | (1ULL << MemgraphCypher::CLEAR)
        | (1ULL << MemgraphCypher::COMMIT)
        | (1ULL << MemgraphCypher::COMMITTED)
        | (1ULL << MemgraphCypher::CONFIG)
        | (1ULL << MemgraphCypher::CONFIGS)
        | (1ULL << MemgraphCypher::CONSUMER_GROUP)
        | (1ULL << MemgraphCypher::CREDENTIALS)
        | (1ULL << MemgraphCypher::CSV)
        | (1ULL << MemgraphCypher::DATA)
        | (1ULL << MemgraphCypher::DELIMITER)
        | (1ULL << MemgraphCypher::DATABASE)
        | (1ULL << MemgraphCypher::DENY)
        | (1ULL << MemgraphCypher::DROP)
        | (1ULL << MemgraphCypher::DUMP)
        | (1ULL << MemgraphCypher::EXECUTE)
        | (1ULL << MemgraphCypher::FOR)
        | (1ULL << MemgraphCypher::FREE)
        | (1ULL << MemgraphCypher::FROM)
        | (1ULL << MemgraphCypher::GLOBAL)
        | (1ULL << MemgraphCypher::GRANT)
        | (1ULL << MemgraphCypher::HEADER)
        | (1ULL << MemgraphCypher::IDENTIFIED)
        | (1ULL << MemgraphCypher::ISOLATION)
        | (1ULL << MemgraphCypher::KAFKA)
        | (1ULL << MemgraphCypher::LEVEL)
        | (1ULL << MemgraphCypher::LOAD)
        | (1ULL << MemgraphCypher::LOCK)
        | (1ULL << MemgraphCypher::MAIN)
        | (1ULL << MemgraphCypher::MODE)
        | (1ULL << MemgraphCypher::NEXT)
        | (1ULL << MemgraphCypher::NO)
        | (1ULL << MemgraphCypher::PASSWORD)
        | (1ULL << MemgraphCypher::PORT)
        | (1ULL << MemgraphCypher::PRIVILEGES)
        | (1ULL << MemgraphCypher::PULSAR)
        | (1ULL << MemgraphCypher::READ)
        | (1ULL << MemgraphCypher::REGISTER)
        | (1ULL << MemgraphCypher::REPLICA)
        | (1ULL << MemgraphCypher::REPLICAS)
        | (1ULL << MemgraphCypher::REPLICATION)
        | (1ULL << MemgraphCypher::REVOKE)
        | (1ULL << MemgraphCypher::ROLE)
        | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
        | (1ULL << (MemgraphCypher::SESSION - 64))
        | (1ULL << (MemgraphCypher::SETTING - 64))
        | (1ULL << (MemgraphCypher::SETTINGS - 64))
        | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
        | (1ULL << (MemgraphCypher::START - 64))
        | (1ULL << (MemgraphCypher::STATS - 64))
        | (1ULL << (MemgraphCypher::STREAM - 64))
        | (1ULL << (MemgraphCypher::STREAMS - 64))
        | (1ULL << (MemgraphCypher::SYNC - 64))
        | (1ULL << (MemgraphCypher::TIMEOUT - 64))
        | (1ULL << (MemgraphCypher::TO - 64))
        | (1ULL << (MemgraphCypher::TOPICS - 64))
        | (1ULL << (MemgraphCypher::TRANSACTION - 64))
        | (1ULL << (MemgraphCypher::TRANSFORM - 64))
        | (1ULL << (MemgraphCypher::TRIGGER - 64))
        | (1ULL << (MemgraphCypher::TRIGGERS - 64))
        | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
        | (1ULL << (MemgraphCypher::UNLOCK - 64))
        | (1ULL << (MemgraphCypher::UPDATE - 64))
        | (1ULL << (MemgraphCypher::USER - 64))
        | (1ULL << (MemgraphCypher::USERS - 64))
        | (1ULL << (MemgraphCypher::VERSION - 64))
        | (1ULL << (MemgraphCypher::LPAREN - 64))
        | (1ULL << (MemgraphCypher::LBRACK - 64))
        | (1ULL << (MemgraphCypher::LBRACE - 64))
        | (1ULL << (MemgraphCypher::DOLLAR - 64))
        | (1ULL << (MemgraphCypher::PLUS - 64))
        | (1ULL << (MemgraphCypher::MINUS - 64))
        | (1ULL << (MemgraphCypher::ALL - 64))
        | (1ULL << (MemgraphCypher::AND - 64))
        | (1ULL << (MemgraphCypher::ANY - 64))
        | (1ULL << (MemgraphCypher::AS - 64))
        | (1ULL << (MemgraphCypher::ASC - 64))
        | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
        | (1ULL << (MemgraphCypher::BFS - 128))
        | (1ULL << (MemgraphCypher::BY - 128))
        | (1ULL << (MemgraphCypher::CALL - 128))
        | (1ULL << (MemgraphCypher::CASE - 128))
        | (1ULL << (MemgraphCypher::COALESCE - 128))
        | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
        | (1ULL << (MemgraphCypher::CONTAINS - 128))
        | (1ULL << (MemgraphCypher::COUNT - 128))
        | (1ULL << (MemgraphCypher::CREATE - 128))
        | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
        | (1ULL << (MemgraphCypher::DELETE - 128))
        | (1ULL << (MemgraphCypher::DESC - 128))
        | (1ULL << (MemgraphCypher::DESCENDING - 128))
        | (1ULL << (MemgraphCypher::DETACH - 128))
        | (1ULL << (MemgraphCypher::DISTINCT - 128))
        | (1ULL << (MemgraphCypher::ELSE - 128))
        | (1ULL << (MemgraphCypher::END - 128))
        | (1ULL << (MemgraphCypher::ENDS - 128))
        | (1ULL << (MemgraphCypher::EXISTS - 128))
        | (1ULL << (MemgraphCypher::EXPLAIN - 128))
        | (1ULL << (MemgraphCypher::EXTRACT - 128))
        | (1ULL << (MemgraphCypher::FALSE - 128))
        | (1ULL << (MemgraphCypher::FILTER - 128))
        | (1ULL << (MemgraphCypher::IN - 128))
        | (1ULL << (MemgraphCypher::INDEX - 128))
        | (1ULL << (MemgraphCypher::INFO - 128))
        | (1ULL << (MemgraphCypher::IS - 128))
        | (1ULL << (MemgraphCypher::KEY - 128))
        | (1ULL << (MemgraphCypher::LIMIT - 128))
        | (1ULL << (MemgraphCypher::L_SKIP - 128))
        | (1ULL << (MemgraphCypher::MATCH - 128))
        | (1ULL << (MemgraphCypher::MERGE - 128))
        | (1ULL << (MemgraphCypher::NODE - 128))
        | (1ULL << (MemgraphCypher::NONE - 128))
        | (1ULL << (MemgraphCypher::NOT - 128))
        | (1ULL << (MemgraphCypher::ON - 128))
        | (1ULL << (MemgraphCypher::OPTIONAL - 128))
        | (1ULL << (MemgraphCypher::OR - 128))
        | (1ULL << (MemgraphCypher::ORDER - 128))
        | (1ULL << (MemgraphCypher::PROCEDURE - 128))
        | (1ULL << (MemgraphCypher::PROFILE - 128))
        | (1ULL << (MemgraphCypher::QUERY - 128))
        | (1ULL << (MemgraphCypher::REDUCE - 128))
        | (1ULL << (MemgraphCypher::REMOVE - 128))
        | (1ULL << (MemgraphCypher::RETURN - 128))
        | (1ULL << (MemgraphCypher::SET - 128))
        | (1ULL << (MemgraphCypher::SHOW - 128))
        | (1ULL << (MemgraphCypher::SINGLE - 128))
        | (1ULL << (MemgraphCypher::STARTS - 128))
        | (1ULL << (MemgraphCypher::STORAGE - 128))
        | (1ULL << (MemgraphCypher::THEN - 128))
        | (1ULL << (MemgraphCypher::TRUE - 128))
        | (1ULL << (MemgraphCypher::TT - 128))
        | (1ULL << (MemgraphCypher::UNION - 128))
        | (1ULL << (MemgraphCypher::UNIQUE - 128))
        | (1ULL << (MemgraphCypher::UNWIND - 128))
        | (1ULL << (MemgraphCypher::WHEN - 128))
        | (1ULL << (MemgraphCypher::WHERE - 128))
        | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
        | (1ULL << (MemgraphCypher::XOR - 192))
        | (1ULL << (MemgraphCypher::YIELD - 192))
        | (1ULL << (MemgraphCypher::StringLiteral - 192))
        | (1ULL << (MemgraphCypher::DecimalLiteral - 192))
        | (1ULL << (MemgraphCypher::OctalLiteral - 192))
        | (1ULL << (MemgraphCypher::HexadecimalLiteral - 192))
        | (1ULL << (MemgraphCypher::FloatingLiteral - 192))
        | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
        | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
        setState(1594);
        dynamic_cast<ListIndexingOrSlicingContext *>(_localctx)->upper_bound = expression();
      }
      setState(1597);
      match(MemgraphCypher::RBRACK);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression2aContext ------------------------------------------------------------------

MemgraphCypher::Expression2aContext::Expression2aContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::Expression2bContext* MemgraphCypher::Expression2aContext::expression2b() {
  return getRuleContext<MemgraphCypher::Expression2bContext>(0);
}

MemgraphCypher::NodeLabelsContext* MemgraphCypher::Expression2aContext::nodeLabels() {
  return getRuleContext<MemgraphCypher::NodeLabelsContext>(0);
}


size_t MemgraphCypher::Expression2aContext::getRuleIndex() const {
  return MemgraphCypher::RuleExpression2a;
}

void MemgraphCypher::Expression2aContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression2a(this);
}

void MemgraphCypher::Expression2aContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression2a(this);
}


antlrcpp::Any MemgraphCypher::Expression2aContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression2a(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression2aContext* MemgraphCypher::expression2a() {
  Expression2aContext *_localctx = _tracker.createInstance<Expression2aContext>(_ctx, getState());
  enterRule(_localctx, 314, MemgraphCypher::RuleExpression2a);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1600);
    expression2b();
    setState(1602);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::COLON) {
      setState(1601);
      nodeLabels();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression2bContext ------------------------------------------------------------------

MemgraphCypher::Expression2bContext::Expression2bContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::AtomContext* MemgraphCypher::Expression2bContext::atom() {
  return getRuleContext<MemgraphCypher::AtomContext>(0);
}

std::vector<MemgraphCypher::PropertyLookupContext *> MemgraphCypher::Expression2bContext::propertyLookup() {
  return getRuleContexts<MemgraphCypher::PropertyLookupContext>();
}

MemgraphCypher::PropertyLookupContext* MemgraphCypher::Expression2bContext::propertyLookup(size_t i) {
  return getRuleContext<MemgraphCypher::PropertyLookupContext>(i);
}


size_t MemgraphCypher::Expression2bContext::getRuleIndex() const {
  return MemgraphCypher::RuleExpression2b;
}

void MemgraphCypher::Expression2bContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression2b(this);
}

void MemgraphCypher::Expression2bContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression2b(this);
}


antlrcpp::Any MemgraphCypher::Expression2bContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExpression2b(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::Expression2bContext* MemgraphCypher::expression2b() {
  Expression2bContext *_localctx = _tracker.createInstance<Expression2bContext>(_ctx, getState());
  enterRule(_localctx, 316, MemgraphCypher::RuleExpression2b);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1604);
    atom();
    setState(1608);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MemgraphCypher::DOT) {
      setState(1605);
      propertyLookup();
      setState(1610);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

MemgraphCypher::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::LiteralContext* MemgraphCypher::AtomContext::literal() {
  return getRuleContext<MemgraphCypher::LiteralContext>(0);
}

MemgraphCypher::ParameterContext* MemgraphCypher::AtomContext::parameter() {
  return getRuleContext<MemgraphCypher::ParameterContext>(0);
}

MemgraphCypher::CaseExpressionContext* MemgraphCypher::AtomContext::caseExpression() {
  return getRuleContext<MemgraphCypher::CaseExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::COUNT() {
  return getToken(MemgraphCypher::COUNT, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::ASTERISK() {
  return getToken(MemgraphCypher::ASTERISK, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}

MemgraphCypher::ListComprehensionContext* MemgraphCypher::AtomContext::listComprehension() {
  return getRuleContext<MemgraphCypher::ListComprehensionContext>(0);
}

MemgraphCypher::PatternComprehensionContext* MemgraphCypher::AtomContext::patternComprehension() {
  return getRuleContext<MemgraphCypher::PatternComprehensionContext>(0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::FILTER() {
  return getToken(MemgraphCypher::FILTER, 0);
}

MemgraphCypher::FilterExpressionContext* MemgraphCypher::AtomContext::filterExpression() {
  return getRuleContext<MemgraphCypher::FilterExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::EXTRACT() {
  return getToken(MemgraphCypher::EXTRACT, 0);
}

MemgraphCypher::ExtractExpressionContext* MemgraphCypher::AtomContext::extractExpression() {
  return getRuleContext<MemgraphCypher::ExtractExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::REDUCE() {
  return getToken(MemgraphCypher::REDUCE, 0);
}

MemgraphCypher::ReduceExpressionContext* MemgraphCypher::AtomContext::reduceExpression() {
  return getRuleContext<MemgraphCypher::ReduceExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::COALESCE() {
  return getToken(MemgraphCypher::COALESCE, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::AtomContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::AtomContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::AtomContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::AtomContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}

tree::TerminalNode* MemgraphCypher::AtomContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::ANY() {
  return getToken(MemgraphCypher::ANY, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::NONE() {
  return getToken(MemgraphCypher::NONE, 0);
}

tree::TerminalNode* MemgraphCypher::AtomContext::SINGLE() {
  return getToken(MemgraphCypher::SINGLE, 0);
}

MemgraphCypher::RelationshipsPatternContext* MemgraphCypher::AtomContext::relationshipsPattern() {
  return getRuleContext<MemgraphCypher::RelationshipsPatternContext>(0);
}

MemgraphCypher::ParenthesizedExpressionContext* MemgraphCypher::AtomContext::parenthesizedExpression() {
  return getRuleContext<MemgraphCypher::ParenthesizedExpressionContext>(0);
}

MemgraphCypher::FunctionInvocationContext* MemgraphCypher::AtomContext::functionInvocation() {
  return getRuleContext<MemgraphCypher::FunctionInvocationContext>(0);
}

MemgraphCypher::VariableContext* MemgraphCypher::AtomContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}


size_t MemgraphCypher::AtomContext::getRuleIndex() const {
  return MemgraphCypher::RuleAtom;
}

void MemgraphCypher::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void MemgraphCypher::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}


antlrcpp::Any MemgraphCypher::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::AtomContext* MemgraphCypher::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 318, MemgraphCypher::RuleAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1671);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1611);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1612);
      parameter();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1613);
      caseExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1614);
      match(MemgraphCypher::COUNT);
      setState(1615);
      match(MemgraphCypher::LPAREN);
      setState(1616);
      match(MemgraphCypher::ASTERISK);
      setState(1617);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1618);
      listComprehension();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1619);
      patternComprehension();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1620);
      match(MemgraphCypher::FILTER);
      setState(1621);
      match(MemgraphCypher::LPAREN);
      setState(1622);
      filterExpression();
      setState(1623);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1625);
      match(MemgraphCypher::EXTRACT);
      setState(1626);
      match(MemgraphCypher::LPAREN);
      setState(1627);
      extractExpression();
      setState(1628);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1630);
      match(MemgraphCypher::REDUCE);
      setState(1631);
      match(MemgraphCypher::LPAREN);
      setState(1632);
      reduceExpression();
      setState(1633);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1635);
      match(MemgraphCypher::COALESCE);
      setState(1636);
      match(MemgraphCypher::LPAREN);
      setState(1637);
      expression();
      setState(1642);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(1638);
        match(MemgraphCypher::COMMA);
        setState(1639);
        expression();
        setState(1644);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1645);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1647);
      match(MemgraphCypher::ALL);
      setState(1648);
      match(MemgraphCypher::LPAREN);
      setState(1649);
      filterExpression();
      setState(1650);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(1652);
      match(MemgraphCypher::ANY);
      setState(1653);
      match(MemgraphCypher::LPAREN);
      setState(1654);
      filterExpression();
      setState(1655);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(1657);
      match(MemgraphCypher::NONE);
      setState(1658);
      match(MemgraphCypher::LPAREN);
      setState(1659);
      filterExpression();
      setState(1660);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(1662);
      match(MemgraphCypher::SINGLE);
      setState(1663);
      match(MemgraphCypher::LPAREN);
      setState(1664);
      filterExpression();
      setState(1665);
      match(MemgraphCypher::RPAREN);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(1667);
      relationshipsPattern();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(1668);
      parenthesizedExpression();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(1669);
      functionInvocation();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(1670);
      variable();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MemgraphCypher::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::NumberLiteralContext* MemgraphCypher::LiteralContext::numberLiteral() {
  return getRuleContext<MemgraphCypher::NumberLiteralContext>(0);
}

tree::TerminalNode* MemgraphCypher::LiteralContext::StringLiteral() {
  return getToken(MemgraphCypher::StringLiteral, 0);
}

MemgraphCypher::BooleanLiteralContext* MemgraphCypher::LiteralContext::booleanLiteral() {
  return getRuleContext<MemgraphCypher::BooleanLiteralContext>(0);
}

tree::TerminalNode* MemgraphCypher::LiteralContext::CYPHERNULL() {
  return getToken(MemgraphCypher::CYPHERNULL, 0);
}

MemgraphCypher::MapLiteralContext* MemgraphCypher::LiteralContext::mapLiteral() {
  return getRuleContext<MemgraphCypher::MapLiteralContext>(0);
}

MemgraphCypher::ListLiteralContext* MemgraphCypher::LiteralContext::listLiteral() {
  return getRuleContext<MemgraphCypher::ListLiteralContext>(0);
}


size_t MemgraphCypher::LiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleLiteral;
}

void MemgraphCypher::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void MemgraphCypher::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any MemgraphCypher::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::LiteralContext* MemgraphCypher::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 320, MemgraphCypher::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1679);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::DecimalLiteral:
      case MemgraphCypher::OctalLiteral:
      case MemgraphCypher::HexadecimalLiteral:
      case MemgraphCypher::FloatingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1673);
        numberLiteral();
        break;
      }

      case MemgraphCypher::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(1674);
        match(MemgraphCypher::StringLiteral);
        break;
      }

      case MemgraphCypher::FALSE:
      case MemgraphCypher::TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(1675);
        booleanLiteral();
        break;
      }

      case MemgraphCypher::CYPHERNULL: {
        enterOuterAlt(_localctx, 4);
        setState(1676);
        match(MemgraphCypher::CYPHERNULL);
        break;
      }

      case MemgraphCypher::LBRACE: {
        enterOuterAlt(_localctx, 5);
        setState(1677);
        mapLiteral();
        break;
      }

      case MemgraphCypher::LBRACK: {
        enterOuterAlt(_localctx, 6);
        setState(1678);
        listLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

MemgraphCypher::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::BooleanLiteralContext::TRUE() {
  return getToken(MemgraphCypher::TRUE, 0);
}

tree::TerminalNode* MemgraphCypher::BooleanLiteralContext::FALSE() {
  return getToken(MemgraphCypher::FALSE, 0);
}


size_t MemgraphCypher::BooleanLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleBooleanLiteral;
}

void MemgraphCypher::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}

void MemgraphCypher::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}


antlrcpp::Any MemgraphCypher::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::BooleanLiteralContext* MemgraphCypher::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 322, MemgraphCypher::RuleBooleanLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1681);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::FALSE

    || _la == MemgraphCypher::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListLiteralContext ------------------------------------------------------------------

MemgraphCypher::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ListLiteralContext::LBRACK() {
  return getToken(MemgraphCypher::LBRACK, 0);
}

tree::TerminalNode* MemgraphCypher::ListLiteralContext::RBRACK() {
  return getToken(MemgraphCypher::RBRACK, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::ListLiteralContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ListLiteralContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::ListLiteralContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::ListLiteralContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::ListLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleListLiteral;
}

void MemgraphCypher::ListLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListLiteral(this);
}

void MemgraphCypher::ListLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListLiteral(this);
}


antlrcpp::Any MemgraphCypher::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ListLiteralContext* MemgraphCypher::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 324, MemgraphCypher::RuleListLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1683);
    match(MemgraphCypher::LBRACK);
    setState(1692);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::LPAREN - 64))
      | (1ULL << (MemgraphCypher::LBRACK - 64))
      | (1ULL << (MemgraphCypher::LBRACE - 64))
      | (1ULL << (MemgraphCypher::DOLLAR - 64))
      | (1ULL << (MemgraphCypher::PLUS - 64))
      | (1ULL << (MemgraphCypher::MINUS - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::COALESCE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::StringLiteral - 192))
      | (1ULL << (MemgraphCypher::DecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::OctalLiteral - 192))
      | (1ULL << (MemgraphCypher::HexadecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::FloatingLiteral - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1684);
      expression();
      setState(1689);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(1685);
        match(MemgraphCypher::COMMA);
        setState(1686);
        expression();
        setState(1691);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1694);
    match(MemgraphCypher::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PartialComparisonExpressionContext ------------------------------------------------------------------

MemgraphCypher::PartialComparisonExpressionContext::PartialComparisonExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::EQ() {
  return getToken(MemgraphCypher::EQ, 0);
}

MemgraphCypher::Expression7Context* MemgraphCypher::PartialComparisonExpressionContext::expression7() {
  return getRuleContext<MemgraphCypher::Expression7Context>(0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::NEQ1() {
  return getToken(MemgraphCypher::NEQ1, 0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::NEQ2() {
  return getToken(MemgraphCypher::NEQ2, 0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::LT() {
  return getToken(MemgraphCypher::LT, 0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::GT() {
  return getToken(MemgraphCypher::GT, 0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::LTE() {
  return getToken(MemgraphCypher::LTE, 0);
}

tree::TerminalNode* MemgraphCypher::PartialComparisonExpressionContext::GTE() {
  return getToken(MemgraphCypher::GTE, 0);
}


size_t MemgraphCypher::PartialComparisonExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RulePartialComparisonExpression;
}

void MemgraphCypher::PartialComparisonExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPartialComparisonExpression(this);
}

void MemgraphCypher::PartialComparisonExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPartialComparisonExpression(this);
}


antlrcpp::Any MemgraphCypher::PartialComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPartialComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PartialComparisonExpressionContext* MemgraphCypher::partialComparisonExpression() {
  PartialComparisonExpressionContext *_localctx = _tracker.createInstance<PartialComparisonExpressionContext>(_ctx, getState());
  enterRule(_localctx, 326, MemgraphCypher::RulePartialComparisonExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1710);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::EQ: {
        enterOuterAlt(_localctx, 1);
        setState(1696);
        match(MemgraphCypher::EQ);
        setState(1697);
        expression7();
        break;
      }

      case MemgraphCypher::NEQ1: {
        enterOuterAlt(_localctx, 2);
        setState(1698);
        match(MemgraphCypher::NEQ1);
        setState(1699);
        expression7();
        break;
      }

      case MemgraphCypher::NEQ2: {
        enterOuterAlt(_localctx, 3);
        setState(1700);
        match(MemgraphCypher::NEQ2);
        setState(1701);
        expression7();
        break;
      }

      case MemgraphCypher::LT: {
        enterOuterAlt(_localctx, 4);
        setState(1702);
        match(MemgraphCypher::LT);
        setState(1703);
        expression7();
        break;
      }

      case MemgraphCypher::GT: {
        enterOuterAlt(_localctx, 5);
        setState(1704);
        match(MemgraphCypher::GT);
        setState(1705);
        expression7();
        break;
      }

      case MemgraphCypher::LTE: {
        enterOuterAlt(_localctx, 6);
        setState(1706);
        match(MemgraphCypher::LTE);
        setState(1707);
        expression7();
        break;
      }

      case MemgraphCypher::GTE: {
        enterOuterAlt(_localctx, 7);
        setState(1708);
        match(MemgraphCypher::GTE);
        setState(1709);
        expression7();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

MemgraphCypher::ParenthesizedExpressionContext::ParenthesizedExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ParenthesizedExpressionContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ParenthesizedExpressionContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::ParenthesizedExpressionContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}


size_t MemgraphCypher::ParenthesizedExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleParenthesizedExpression;
}

void MemgraphCypher::ParenthesizedExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedExpression(this);
}

void MemgraphCypher::ParenthesizedExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedExpression(this);
}


antlrcpp::Any MemgraphCypher::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ParenthesizedExpressionContext* MemgraphCypher::parenthesizedExpression() {
  ParenthesizedExpressionContext *_localctx = _tracker.createInstance<ParenthesizedExpressionContext>(_ctx, getState());
  enterRule(_localctx, 328, MemgraphCypher::RuleParenthesizedExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1712);
    match(MemgraphCypher::LPAREN);
    setState(1713);
    expression();
    setState(1714);
    match(MemgraphCypher::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationshipsPatternContext ------------------------------------------------------------------

MemgraphCypher::RelationshipsPatternContext::RelationshipsPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::NodePatternContext* MemgraphCypher::RelationshipsPatternContext::nodePattern() {
  return getRuleContext<MemgraphCypher::NodePatternContext>(0);
}

std::vector<MemgraphCypher::PatternElementChainContext *> MemgraphCypher::RelationshipsPatternContext::patternElementChain() {
  return getRuleContexts<MemgraphCypher::PatternElementChainContext>();
}

MemgraphCypher::PatternElementChainContext* MemgraphCypher::RelationshipsPatternContext::patternElementChain(size_t i) {
  return getRuleContext<MemgraphCypher::PatternElementChainContext>(i);
}


size_t MemgraphCypher::RelationshipsPatternContext::getRuleIndex() const {
  return MemgraphCypher::RuleRelationshipsPattern;
}

void MemgraphCypher::RelationshipsPatternContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationshipsPattern(this);
}

void MemgraphCypher::RelationshipsPatternContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationshipsPattern(this);
}


antlrcpp::Any MemgraphCypher::RelationshipsPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitRelationshipsPattern(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::RelationshipsPatternContext* MemgraphCypher::relationshipsPattern() {
  RelationshipsPatternContext *_localctx = _tracker.createInstance<RelationshipsPatternContext>(_ctx, getState());
  enterRule(_localctx, 330, MemgraphCypher::RuleRelationshipsPattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1716);
    nodePattern();
    setState(1718); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1717);
              patternElementChain();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1720); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilterExpressionContext ------------------------------------------------------------------

MemgraphCypher::FilterExpressionContext::FilterExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::IdInCollContext* MemgraphCypher::FilterExpressionContext::idInColl() {
  return getRuleContext<MemgraphCypher::IdInCollContext>(0);
}

MemgraphCypher::WhereContext* MemgraphCypher::FilterExpressionContext::where() {
  return getRuleContext<MemgraphCypher::WhereContext>(0);
}


size_t MemgraphCypher::FilterExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleFilterExpression;
}

void MemgraphCypher::FilterExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilterExpression(this);
}

void MemgraphCypher::FilterExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilterExpression(this);
}


antlrcpp::Any MemgraphCypher::FilterExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitFilterExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::FilterExpressionContext* MemgraphCypher::filterExpression() {
  FilterExpressionContext *_localctx = _tracker.createInstance<FilterExpressionContext>(_ctx, getState());
  enterRule(_localctx, 332, MemgraphCypher::RuleFilterExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1722);
    idInColl();
    setState(1724);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WHERE) {
      setState(1723);
      where();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReduceExpressionContext ------------------------------------------------------------------

MemgraphCypher::ReduceExpressionContext::ReduceExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ReduceExpressionContext::EQ() {
  return getToken(MemgraphCypher::EQ, 0);
}

tree::TerminalNode* MemgraphCypher::ReduceExpressionContext::COMMA() {
  return getToken(MemgraphCypher::COMMA, 0);
}

MemgraphCypher::IdInCollContext* MemgraphCypher::ReduceExpressionContext::idInColl() {
  return getRuleContext<MemgraphCypher::IdInCollContext>(0);
}

tree::TerminalNode* MemgraphCypher::ReduceExpressionContext::PIPE() {
  return getToken(MemgraphCypher::PIPE, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::ReduceExpressionContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ReduceExpressionContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

MemgraphCypher::VariableContext* MemgraphCypher::ReduceExpressionContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}


size_t MemgraphCypher::ReduceExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleReduceExpression;
}

void MemgraphCypher::ReduceExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReduceExpression(this);
}

void MemgraphCypher::ReduceExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReduceExpression(this);
}


antlrcpp::Any MemgraphCypher::ReduceExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitReduceExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ReduceExpressionContext* MemgraphCypher::reduceExpression() {
  ReduceExpressionContext *_localctx = _tracker.createInstance<ReduceExpressionContext>(_ctx, getState());
  enterRule(_localctx, 334, MemgraphCypher::RuleReduceExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1726);
    dynamic_cast<ReduceExpressionContext *>(_localctx)->accumulator = variable();
    setState(1727);
    match(MemgraphCypher::EQ);
    setState(1728);
    dynamic_cast<ReduceExpressionContext *>(_localctx)->initial = expression();
    setState(1729);
    match(MemgraphCypher::COMMA);
    setState(1730);
    idInColl();
    setState(1731);
    match(MemgraphCypher::PIPE);
    setState(1732);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExtractExpressionContext ------------------------------------------------------------------

MemgraphCypher::ExtractExpressionContext::ExtractExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::IdInCollContext* MemgraphCypher::ExtractExpressionContext::idInColl() {
  return getRuleContext<MemgraphCypher::IdInCollContext>(0);
}

tree::TerminalNode* MemgraphCypher::ExtractExpressionContext::PIPE() {
  return getToken(MemgraphCypher::PIPE, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ExtractExpressionContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::ExtractExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleExtractExpression;
}

void MemgraphCypher::ExtractExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtractExpression(this);
}

void MemgraphCypher::ExtractExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtractExpression(this);
}


antlrcpp::Any MemgraphCypher::ExtractExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitExtractExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ExtractExpressionContext* MemgraphCypher::extractExpression() {
  ExtractExpressionContext *_localctx = _tracker.createInstance<ExtractExpressionContext>(_ctx, getState());
  enterRule(_localctx, 336, MemgraphCypher::RuleExtractExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1734);
    idInColl();
    setState(1735);
    match(MemgraphCypher::PIPE);
    setState(1736);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdInCollContext ------------------------------------------------------------------

MemgraphCypher::IdInCollContext::IdInCollContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::VariableContext* MemgraphCypher::IdInCollContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

tree::TerminalNode* MemgraphCypher::IdInCollContext::IN() {
  return getToken(MemgraphCypher::IN, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::IdInCollContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::IdInCollContext::getRuleIndex() const {
  return MemgraphCypher::RuleIdInColl;
}

void MemgraphCypher::IdInCollContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdInColl(this);
}

void MemgraphCypher::IdInCollContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdInColl(this);
}


antlrcpp::Any MemgraphCypher::IdInCollContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIdInColl(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IdInCollContext* MemgraphCypher::idInColl() {
  IdInCollContext *_localctx = _tracker.createInstance<IdInCollContext>(_ctx, getState());
  enterRule(_localctx, 338, MemgraphCypher::RuleIdInColl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1738);
    variable();
    setState(1739);
    match(MemgraphCypher::IN);
    setState(1740);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionInvocationContext ------------------------------------------------------------------

MemgraphCypher::FunctionInvocationContext::FunctionInvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::FunctionNameContext* MemgraphCypher::FunctionInvocationContext::functionName() {
  return getRuleContext<MemgraphCypher::FunctionNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::FunctionInvocationContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::FunctionInvocationContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}

tree::TerminalNode* MemgraphCypher::FunctionInvocationContext::DISTINCT() {
  return getToken(MemgraphCypher::DISTINCT, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::FunctionInvocationContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::FunctionInvocationContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::FunctionInvocationContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::FunctionInvocationContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::FunctionInvocationContext::getRuleIndex() const {
  return MemgraphCypher::RuleFunctionInvocation;
}

void MemgraphCypher::FunctionInvocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionInvocation(this);
}

void MemgraphCypher::FunctionInvocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionInvocation(this);
}


antlrcpp::Any MemgraphCypher::FunctionInvocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitFunctionInvocation(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::FunctionInvocationContext* MemgraphCypher::functionInvocation() {
  FunctionInvocationContext *_localctx = _tracker.createInstance<FunctionInvocationContext>(_ctx, getState());
  enterRule(_localctx, 340, MemgraphCypher::RuleFunctionInvocation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1742);
    functionName();
    setState(1743);
    match(MemgraphCypher::LPAREN);
    setState(1745);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
    case 1: {
      setState(1744);
      match(MemgraphCypher::DISTINCT);
      break;
    }

    default:
      break;
    }
    setState(1755);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::LPAREN - 64))
      | (1ULL << (MemgraphCypher::LBRACK - 64))
      | (1ULL << (MemgraphCypher::LBRACE - 64))
      | (1ULL << (MemgraphCypher::DOLLAR - 64))
      | (1ULL << (MemgraphCypher::PLUS - 64))
      | (1ULL << (MemgraphCypher::MINUS - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::COALESCE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::StringLiteral - 192))
      | (1ULL << (MemgraphCypher::DecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::OctalLiteral - 192))
      | (1ULL << (MemgraphCypher::HexadecimalLiteral - 192))
      | (1ULL << (MemgraphCypher::FloatingLiteral - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1747);
      expression();
      setState(1752);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(1748);
        match(MemgraphCypher::COMMA);
        setState(1749);
        expression();
        setState(1754);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1757);
    match(MemgraphCypher::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

MemgraphCypher::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::FunctionNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::FunctionNameContext::getRuleIndex() const {
  return MemgraphCypher::RuleFunctionName;
}

void MemgraphCypher::FunctionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionName(this);
}

void MemgraphCypher::FunctionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionName(this);
}


antlrcpp::Any MemgraphCypher::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::FunctionNameContext* MemgraphCypher::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 342, MemgraphCypher::RuleFunctionName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1759);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListComprehensionContext ------------------------------------------------------------------

MemgraphCypher::ListComprehensionContext::ListComprehensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ListComprehensionContext::LBRACK() {
  return getToken(MemgraphCypher::LBRACK, 0);
}

MemgraphCypher::FilterExpressionContext* MemgraphCypher::ListComprehensionContext::filterExpression() {
  return getRuleContext<MemgraphCypher::FilterExpressionContext>(0);
}

tree::TerminalNode* MemgraphCypher::ListComprehensionContext::RBRACK() {
  return getToken(MemgraphCypher::RBRACK, 0);
}

tree::TerminalNode* MemgraphCypher::ListComprehensionContext::PIPE() {
  return getToken(MemgraphCypher::PIPE, 0);
}

MemgraphCypher::ExpressionContext* MemgraphCypher::ListComprehensionContext::expression() {
  return getRuleContext<MemgraphCypher::ExpressionContext>(0);
}


size_t MemgraphCypher::ListComprehensionContext::getRuleIndex() const {
  return MemgraphCypher::RuleListComprehension;
}

void MemgraphCypher::ListComprehensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListComprehension(this);
}

void MemgraphCypher::ListComprehensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListComprehension(this);
}


antlrcpp::Any MemgraphCypher::ListComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitListComprehension(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ListComprehensionContext* MemgraphCypher::listComprehension() {
  ListComprehensionContext *_localctx = _tracker.createInstance<ListComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 344, MemgraphCypher::RuleListComprehension);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1761);
    match(MemgraphCypher::LBRACK);
    setState(1762);
    filterExpression();
    setState(1765);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::PIPE) {
      setState(1763);
      match(MemgraphCypher::PIPE);
      setState(1764);
      expression();
    }
    setState(1767);
    match(MemgraphCypher::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternComprehensionContext ------------------------------------------------------------------

MemgraphCypher::PatternComprehensionContext::PatternComprehensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PatternComprehensionContext::LBRACK() {
  return getToken(MemgraphCypher::LBRACK, 0);
}

MemgraphCypher::RelationshipsPatternContext* MemgraphCypher::PatternComprehensionContext::relationshipsPattern() {
  return getRuleContext<MemgraphCypher::RelationshipsPatternContext>(0);
}

tree::TerminalNode* MemgraphCypher::PatternComprehensionContext::PIPE() {
  return getToken(MemgraphCypher::PIPE, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::PatternComprehensionContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::PatternComprehensionContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

tree::TerminalNode* MemgraphCypher::PatternComprehensionContext::RBRACK() {
  return getToken(MemgraphCypher::RBRACK, 0);
}

MemgraphCypher::VariableContext* MemgraphCypher::PatternComprehensionContext::variable() {
  return getRuleContext<MemgraphCypher::VariableContext>(0);
}

tree::TerminalNode* MemgraphCypher::PatternComprehensionContext::EQ() {
  return getToken(MemgraphCypher::EQ, 0);
}

tree::TerminalNode* MemgraphCypher::PatternComprehensionContext::WHERE() {
  return getToken(MemgraphCypher::WHERE, 0);
}


size_t MemgraphCypher::PatternComprehensionContext::getRuleIndex() const {
  return MemgraphCypher::RulePatternComprehension;
}

void MemgraphCypher::PatternComprehensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternComprehension(this);
}

void MemgraphCypher::PatternComprehensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternComprehension(this);
}


antlrcpp::Any MemgraphCypher::PatternComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPatternComprehension(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PatternComprehensionContext* MemgraphCypher::patternComprehension() {
  PatternComprehensionContext *_localctx = _tracker.createInstance<PatternComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 346, MemgraphCypher::RulePatternComprehension);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1769);
    match(MemgraphCypher::LBRACK);
    setState(1773);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1770);
      variable();
      setState(1771);
      match(MemgraphCypher::EQ);
    }
    setState(1775);
    relationshipsPattern();
    setState(1778);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::WHERE) {
      setState(1776);
      match(MemgraphCypher::WHERE);
      setState(1777);
      expression();
    }
    setState(1780);
    match(MemgraphCypher::PIPE);
    setState(1781);
    expression();
    setState(1782);
    match(MemgraphCypher::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyLookupContext ------------------------------------------------------------------

MemgraphCypher::PropertyLookupContext::PropertyLookupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::PropertyLookupContext::DOT() {
  return getToken(MemgraphCypher::DOT, 0);
}

MemgraphCypher::PropertyKeyNameContext* MemgraphCypher::PropertyLookupContext::propertyKeyName() {
  return getRuleContext<MemgraphCypher::PropertyKeyNameContext>(0);
}


size_t MemgraphCypher::PropertyLookupContext::getRuleIndex() const {
  return MemgraphCypher::RulePropertyLookup;
}

void MemgraphCypher::PropertyLookupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyLookup(this);
}

void MemgraphCypher::PropertyLookupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyLookup(this);
}


antlrcpp::Any MemgraphCypher::PropertyLookupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPropertyLookup(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PropertyLookupContext* MemgraphCypher::propertyLookup() {
  PropertyLookupContext *_localctx = _tracker.createInstance<PropertyLookupContext>(_ctx, getState());
  enterRule(_localctx, 348, MemgraphCypher::RulePropertyLookup);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1784);
    match(MemgraphCypher::DOT);

    setState(1785);
    propertyKeyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseExpressionContext ------------------------------------------------------------------

MemgraphCypher::CaseExpressionContext::CaseExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CaseExpressionContext::END() {
  return getToken(MemgraphCypher::END, 0);
}

tree::TerminalNode* MemgraphCypher::CaseExpressionContext::ELSE() {
  return getToken(MemgraphCypher::ELSE, 0);
}

tree::TerminalNode* MemgraphCypher::CaseExpressionContext::CASE() {
  return getToken(MemgraphCypher::CASE, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::CaseExpressionContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::CaseExpressionContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

std::vector<MemgraphCypher::CaseAlternativesContext *> MemgraphCypher::CaseExpressionContext::caseAlternatives() {
  return getRuleContexts<MemgraphCypher::CaseAlternativesContext>();
}

MemgraphCypher::CaseAlternativesContext* MemgraphCypher::CaseExpressionContext::caseAlternatives(size_t i) {
  return getRuleContext<MemgraphCypher::CaseAlternativesContext>(i);
}


size_t MemgraphCypher::CaseExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RuleCaseExpression;
}

void MemgraphCypher::CaseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseExpression(this);
}

void MemgraphCypher::CaseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseExpression(this);
}


antlrcpp::Any MemgraphCypher::CaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCaseExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CaseExpressionContext* MemgraphCypher::caseExpression() {
  CaseExpressionContext *_localctx = _tracker.createInstance<CaseExpressionContext>(_ctx, getState());
  enterRule(_localctx, 350, MemgraphCypher::RuleCaseExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1800);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx)) {
    case 1: {
      setState(1787);
      match(MemgraphCypher::CASE);
      setState(1789); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1788);
        caseAlternatives();
        setState(1791); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == MemgraphCypher::WHEN);
      break;
    }

    case 2: {
      setState(1793);
      match(MemgraphCypher::CASE);
      setState(1794);
      dynamic_cast<CaseExpressionContext *>(_localctx)->test = expression();
      setState(1796); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1795);
        caseAlternatives();
        setState(1798); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == MemgraphCypher::WHEN);
      break;
    }

    default:
      break;
    }
    setState(1804);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::ELSE) {
      setState(1802);
      match(MemgraphCypher::ELSE);
      setState(1803);
      dynamic_cast<CaseExpressionContext *>(_localctx)->else_expression = expression();
    }
    setState(1806);
    match(MemgraphCypher::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseAlternativesContext ------------------------------------------------------------------

MemgraphCypher::CaseAlternativesContext::CaseAlternativesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CaseAlternativesContext::WHEN() {
  return getToken(MemgraphCypher::WHEN, 0);
}

tree::TerminalNode* MemgraphCypher::CaseAlternativesContext::THEN() {
  return getToken(MemgraphCypher::THEN, 0);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::CaseAlternativesContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::CaseAlternativesContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}


size_t MemgraphCypher::CaseAlternativesContext::getRuleIndex() const {
  return MemgraphCypher::RuleCaseAlternatives;
}

void MemgraphCypher::CaseAlternativesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseAlternatives(this);
}

void MemgraphCypher::CaseAlternativesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseAlternatives(this);
}


antlrcpp::Any MemgraphCypher::CaseAlternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCaseAlternatives(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CaseAlternativesContext* MemgraphCypher::caseAlternatives() {
  CaseAlternativesContext *_localctx = _tracker.createInstance<CaseAlternativesContext>(_ctx, getState());
  enterRule(_localctx, 352, MemgraphCypher::RuleCaseAlternatives);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1808);
    match(MemgraphCypher::WHEN);
    setState(1809);
    dynamic_cast<CaseAlternativesContext *>(_localctx)->when_expression = expression();
    setState(1810);
    match(MemgraphCypher::THEN);
    setState(1811);
    dynamic_cast<CaseAlternativesContext *>(_localctx)->then_expression = expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

MemgraphCypher::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::VariableContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::VariableContext::getRuleIndex() const {
  return MemgraphCypher::RuleVariable;
}

void MemgraphCypher::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void MemgraphCypher::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}


antlrcpp::Any MemgraphCypher::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::VariableContext* MemgraphCypher::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 354, MemgraphCypher::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1813);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberLiteralContext ------------------------------------------------------------------

MemgraphCypher::NumberLiteralContext::NumberLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::DoubleLiteralContext* MemgraphCypher::NumberLiteralContext::doubleLiteral() {
  return getRuleContext<MemgraphCypher::DoubleLiteralContext>(0);
}

MemgraphCypher::IntegerLiteralContext* MemgraphCypher::NumberLiteralContext::integerLiteral() {
  return getRuleContext<MemgraphCypher::IntegerLiteralContext>(0);
}


size_t MemgraphCypher::NumberLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleNumberLiteral;
}

void MemgraphCypher::NumberLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberLiteral(this);
}

void MemgraphCypher::NumberLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberLiteral(this);
}


antlrcpp::Any MemgraphCypher::NumberLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitNumberLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::NumberLiteralContext* MemgraphCypher::numberLiteral() {
  NumberLiteralContext *_localctx = _tracker.createInstance<NumberLiteralContext>(_ctx, getState());
  enterRule(_localctx, 356, MemgraphCypher::RuleNumberLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1817);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::FloatingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1815);
        doubleLiteral();
        break;
      }

      case MemgraphCypher::DecimalLiteral:
      case MemgraphCypher::OctalLiteral:
      case MemgraphCypher::HexadecimalLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(1816);
        integerLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapLiteralContext ------------------------------------------------------------------

MemgraphCypher::MapLiteralContext::MapLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::MapLiteralContext::LBRACE() {
  return getToken(MemgraphCypher::LBRACE, 0);
}

tree::TerminalNode* MemgraphCypher::MapLiteralContext::RBRACE() {
  return getToken(MemgraphCypher::RBRACE, 0);
}

std::vector<MemgraphCypher::PropertyKeyNameContext *> MemgraphCypher::MapLiteralContext::propertyKeyName() {
  return getRuleContexts<MemgraphCypher::PropertyKeyNameContext>();
}

MemgraphCypher::PropertyKeyNameContext* MemgraphCypher::MapLiteralContext::propertyKeyName(size_t i) {
  return getRuleContext<MemgraphCypher::PropertyKeyNameContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::MapLiteralContext::COLON() {
  return getTokens(MemgraphCypher::COLON);
}

tree::TerminalNode* MemgraphCypher::MapLiteralContext::COLON(size_t i) {
  return getToken(MemgraphCypher::COLON, i);
}

std::vector<MemgraphCypher::ExpressionContext *> MemgraphCypher::MapLiteralContext::expression() {
  return getRuleContexts<MemgraphCypher::ExpressionContext>();
}

MemgraphCypher::ExpressionContext* MemgraphCypher::MapLiteralContext::expression(size_t i) {
  return getRuleContext<MemgraphCypher::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MemgraphCypher::MapLiteralContext::COMMA() {
  return getTokens(MemgraphCypher::COMMA);
}

tree::TerminalNode* MemgraphCypher::MapLiteralContext::COMMA(size_t i) {
  return getToken(MemgraphCypher::COMMA, i);
}


size_t MemgraphCypher::MapLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleMapLiteral;
}

void MemgraphCypher::MapLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapLiteral(this);
}

void MemgraphCypher::MapLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapLiteral(this);
}


antlrcpp::Any MemgraphCypher::MapLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitMapLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::MapLiteralContext* MemgraphCypher::mapLiteral() {
  MapLiteralContext *_localctx = _tracker.createInstance<MapLiteralContext>(_ctx, getState());
  enterRule(_localctx, 358, MemgraphCypher::RuleMapLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1819);
    match(MemgraphCypher::LBRACE);
    setState(1833);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MemgraphCypher::AFTER)
      | (1ULL << MemgraphCypher::ALTER)
      | (1ULL << MemgraphCypher::ASYNC)
      | (1ULL << MemgraphCypher::AUTH)
      | (1ULL << MemgraphCypher::BAD)
      | (1ULL << MemgraphCypher::BATCH_INTERVAL)
      | (1ULL << MemgraphCypher::BATCH_LIMIT)
      | (1ULL << MemgraphCypher::BATCH_SIZE)
      | (1ULL << MemgraphCypher::BEFORE)
      | (1ULL << MemgraphCypher::BOOTSTRAP_SERVERS)
      | (1ULL << MemgraphCypher::CHECK)
      | (1ULL << MemgraphCypher::CLEAR)
      | (1ULL << MemgraphCypher::COMMIT)
      | (1ULL << MemgraphCypher::COMMITTED)
      | (1ULL << MemgraphCypher::CONFIG)
      | (1ULL << MemgraphCypher::CONFIGS)
      | (1ULL << MemgraphCypher::CONSUMER_GROUP)
      | (1ULL << MemgraphCypher::CREDENTIALS)
      | (1ULL << MemgraphCypher::CSV)
      | (1ULL << MemgraphCypher::DATA)
      | (1ULL << MemgraphCypher::DELIMITER)
      | (1ULL << MemgraphCypher::DATABASE)
      | (1ULL << MemgraphCypher::DENY)
      | (1ULL << MemgraphCypher::DROP)
      | (1ULL << MemgraphCypher::DUMP)
      | (1ULL << MemgraphCypher::EXECUTE)
      | (1ULL << MemgraphCypher::FOR)
      | (1ULL << MemgraphCypher::FREE)
      | (1ULL << MemgraphCypher::FROM)
      | (1ULL << MemgraphCypher::GLOBAL)
      | (1ULL << MemgraphCypher::GRANT)
      | (1ULL << MemgraphCypher::HEADER)
      | (1ULL << MemgraphCypher::IDENTIFIED)
      | (1ULL << MemgraphCypher::ISOLATION)
      | (1ULL << MemgraphCypher::KAFKA)
      | (1ULL << MemgraphCypher::LEVEL)
      | (1ULL << MemgraphCypher::LOAD)
      | (1ULL << MemgraphCypher::LOCK)
      | (1ULL << MemgraphCypher::MAIN)
      | (1ULL << MemgraphCypher::MODE)
      | (1ULL << MemgraphCypher::NEXT)
      | (1ULL << MemgraphCypher::NO)
      | (1ULL << MemgraphCypher::PASSWORD)
      | (1ULL << MemgraphCypher::PORT)
      | (1ULL << MemgraphCypher::PRIVILEGES)
      | (1ULL << MemgraphCypher::PULSAR)
      | (1ULL << MemgraphCypher::READ)
      | (1ULL << MemgraphCypher::REGISTER)
      | (1ULL << MemgraphCypher::REPLICA)
      | (1ULL << MemgraphCypher::REPLICAS)
      | (1ULL << MemgraphCypher::REPLICATION)
      | (1ULL << MemgraphCypher::REVOKE)
      | (1ULL << MemgraphCypher::ROLE)
      | (1ULL << MemgraphCypher::ROLES))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (MemgraphCypher::QUOTE - 64))
      | (1ULL << (MemgraphCypher::SESSION - 64))
      | (1ULL << (MemgraphCypher::SETTING - 64))
      | (1ULL << (MemgraphCypher::SETTINGS - 64))
      | (1ULL << (MemgraphCypher::SNAPSHOT - 64))
      | (1ULL << (MemgraphCypher::START - 64))
      | (1ULL << (MemgraphCypher::STATS - 64))
      | (1ULL << (MemgraphCypher::STREAM - 64))
      | (1ULL << (MemgraphCypher::STREAMS - 64))
      | (1ULL << (MemgraphCypher::SYNC - 64))
      | (1ULL << (MemgraphCypher::TIMEOUT - 64))
      | (1ULL << (MemgraphCypher::TO - 64))
      | (1ULL << (MemgraphCypher::TOPICS - 64))
      | (1ULL << (MemgraphCypher::TRANSACTION - 64))
      | (1ULL << (MemgraphCypher::TRANSFORM - 64))
      | (1ULL << (MemgraphCypher::TRIGGER - 64))
      | (1ULL << (MemgraphCypher::TRIGGERS - 64))
      | (1ULL << (MemgraphCypher::UNCOMMITTED - 64))
      | (1ULL << (MemgraphCypher::UNLOCK - 64))
      | (1ULL << (MemgraphCypher::UPDATE - 64))
      | (1ULL << (MemgraphCypher::USER - 64))
      | (1ULL << (MemgraphCypher::USERS - 64))
      | (1ULL << (MemgraphCypher::VERSION - 64))
      | (1ULL << (MemgraphCypher::ALL - 64))
      | (1ULL << (MemgraphCypher::AND - 64))
      | (1ULL << (MemgraphCypher::ANY - 64))
      | (1ULL << (MemgraphCypher::AS - 64))
      | (1ULL << (MemgraphCypher::ASC - 64))
      | (1ULL << (MemgraphCypher::ASCENDING - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (MemgraphCypher::ASSERT - 128))
      | (1ULL << (MemgraphCypher::BFS - 128))
      | (1ULL << (MemgraphCypher::BY - 128))
      | (1ULL << (MemgraphCypher::CALL - 128))
      | (1ULL << (MemgraphCypher::CASE - 128))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 128))
      | (1ULL << (MemgraphCypher::CONTAINS - 128))
      | (1ULL << (MemgraphCypher::COUNT - 128))
      | (1ULL << (MemgraphCypher::CREATE - 128))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 128))
      | (1ULL << (MemgraphCypher::DELETE - 128))
      | (1ULL << (MemgraphCypher::DESC - 128))
      | (1ULL << (MemgraphCypher::DESCENDING - 128))
      | (1ULL << (MemgraphCypher::DETACH - 128))
      | (1ULL << (MemgraphCypher::DISTINCT - 128))
      | (1ULL << (MemgraphCypher::ELSE - 128))
      | (1ULL << (MemgraphCypher::END - 128))
      | (1ULL << (MemgraphCypher::ENDS - 128))
      | (1ULL << (MemgraphCypher::EXISTS - 128))
      | (1ULL << (MemgraphCypher::EXPLAIN - 128))
      | (1ULL << (MemgraphCypher::EXTRACT - 128))
      | (1ULL << (MemgraphCypher::FALSE - 128))
      | (1ULL << (MemgraphCypher::FILTER - 128))
      | (1ULL << (MemgraphCypher::IN - 128))
      | (1ULL << (MemgraphCypher::INDEX - 128))
      | (1ULL << (MemgraphCypher::INFO - 128))
      | (1ULL << (MemgraphCypher::IS - 128))
      | (1ULL << (MemgraphCypher::KEY - 128))
      | (1ULL << (MemgraphCypher::LIMIT - 128))
      | (1ULL << (MemgraphCypher::L_SKIP - 128))
      | (1ULL << (MemgraphCypher::MATCH - 128))
      | (1ULL << (MemgraphCypher::MERGE - 128))
      | (1ULL << (MemgraphCypher::NODE - 128))
      | (1ULL << (MemgraphCypher::NONE - 128))
      | (1ULL << (MemgraphCypher::NOT - 128))
      | (1ULL << (MemgraphCypher::ON - 128))
      | (1ULL << (MemgraphCypher::OPTIONAL - 128))
      | (1ULL << (MemgraphCypher::OR - 128))
      | (1ULL << (MemgraphCypher::ORDER - 128))
      | (1ULL << (MemgraphCypher::PROCEDURE - 128))
      | (1ULL << (MemgraphCypher::PROFILE - 128))
      | (1ULL << (MemgraphCypher::QUERY - 128))
      | (1ULL << (MemgraphCypher::REDUCE - 128))
      | (1ULL << (MemgraphCypher::REMOVE - 128))
      | (1ULL << (MemgraphCypher::RETURN - 128))
      | (1ULL << (MemgraphCypher::SET - 128))
      | (1ULL << (MemgraphCypher::SHOW - 128))
      | (1ULL << (MemgraphCypher::SINGLE - 128))
      | (1ULL << (MemgraphCypher::STARTS - 128))
      | (1ULL << (MemgraphCypher::STORAGE - 128))
      | (1ULL << (MemgraphCypher::THEN - 128))
      | (1ULL << (MemgraphCypher::TRUE - 128))
      | (1ULL << (MemgraphCypher::TT - 128))
      | (1ULL << (MemgraphCypher::UNION - 128))
      | (1ULL << (MemgraphCypher::UNIQUE - 128))
      | (1ULL << (MemgraphCypher::UNWIND - 128))
      | (1ULL << (MemgraphCypher::WHEN - 128))
      | (1ULL << (MemgraphCypher::WHERE - 128))
      | (1ULL << (MemgraphCypher::WITH - 128)))) != 0) || ((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (MemgraphCypher::WSHORTEST - 192))
      | (1ULL << (MemgraphCypher::XOR - 192))
      | (1ULL << (MemgraphCypher::YIELD - 192))
      | (1ULL << (MemgraphCypher::UnescapedSymbolicName - 192))
      | (1ULL << (MemgraphCypher::EscapedSymbolicName - 192)))) != 0)) {
      setState(1820);
      propertyKeyName();
      setState(1821);
      match(MemgraphCypher::COLON);
      setState(1822);
      expression();
      setState(1830);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MemgraphCypher::COMMA) {
        setState(1823);
        match(MemgraphCypher::COMMA);
        setState(1824);
        propertyKeyName();
        setState(1825);
        match(MemgraphCypher::COLON);
        setState(1826);
        expression();
        setState(1832);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1835);
    match(MemgraphCypher::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

MemgraphCypher::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::ParameterContext::DOLLAR() {
  return getToken(MemgraphCypher::DOLLAR, 0);
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::ParameterContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::ParameterContext::DecimalLiteral() {
  return getToken(MemgraphCypher::DecimalLiteral, 0);
}


size_t MemgraphCypher::ParameterContext::getRuleIndex() const {
  return MemgraphCypher::RuleParameter;
}

void MemgraphCypher::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void MemgraphCypher::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


antlrcpp::Any MemgraphCypher::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::ParameterContext* MemgraphCypher::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 360, MemgraphCypher::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1837);
    match(MemgraphCypher::DOLLAR);
    setState(1840);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MemgraphCypher::AFTER:
      case MemgraphCypher::ALTER:
      case MemgraphCypher::ASYNC:
      case MemgraphCypher::AUTH:
      case MemgraphCypher::BAD:
      case MemgraphCypher::BATCH_INTERVAL:
      case MemgraphCypher::BATCH_LIMIT:
      case MemgraphCypher::BATCH_SIZE:
      case MemgraphCypher::BEFORE:
      case MemgraphCypher::BOOTSTRAP_SERVERS:
      case MemgraphCypher::CHECK:
      case MemgraphCypher::CLEAR:
      case MemgraphCypher::COMMIT:
      case MemgraphCypher::COMMITTED:
      case MemgraphCypher::CONFIG:
      case MemgraphCypher::CONFIGS:
      case MemgraphCypher::CONSUMER_GROUP:
      case MemgraphCypher::CREDENTIALS:
      case MemgraphCypher::CSV:
      case MemgraphCypher::DATA:
      case MemgraphCypher::DELIMITER:
      case MemgraphCypher::DATABASE:
      case MemgraphCypher::DENY:
      case MemgraphCypher::DROP:
      case MemgraphCypher::DUMP:
      case MemgraphCypher::EXECUTE:
      case MemgraphCypher::FOR:
      case MemgraphCypher::FREE:
      case MemgraphCypher::FROM:
      case MemgraphCypher::GLOBAL:
      case MemgraphCypher::GRANT:
      case MemgraphCypher::HEADER:
      case MemgraphCypher::IDENTIFIED:
      case MemgraphCypher::ISOLATION:
      case MemgraphCypher::KAFKA:
      case MemgraphCypher::LEVEL:
      case MemgraphCypher::LOAD:
      case MemgraphCypher::LOCK:
      case MemgraphCypher::MAIN:
      case MemgraphCypher::MODE:
      case MemgraphCypher::NEXT:
      case MemgraphCypher::NO:
      case MemgraphCypher::PASSWORD:
      case MemgraphCypher::PORT:
      case MemgraphCypher::PRIVILEGES:
      case MemgraphCypher::PULSAR:
      case MemgraphCypher::READ:
      case MemgraphCypher::REGISTER:
      case MemgraphCypher::REPLICA:
      case MemgraphCypher::REPLICAS:
      case MemgraphCypher::REPLICATION:
      case MemgraphCypher::REVOKE:
      case MemgraphCypher::ROLE:
      case MemgraphCypher::ROLES:
      case MemgraphCypher::QUOTE:
      case MemgraphCypher::SESSION:
      case MemgraphCypher::SETTING:
      case MemgraphCypher::SETTINGS:
      case MemgraphCypher::SNAPSHOT:
      case MemgraphCypher::START:
      case MemgraphCypher::STATS:
      case MemgraphCypher::STREAM:
      case MemgraphCypher::STREAMS:
      case MemgraphCypher::SYNC:
      case MemgraphCypher::TIMEOUT:
      case MemgraphCypher::TO:
      case MemgraphCypher::TOPICS:
      case MemgraphCypher::TRANSACTION:
      case MemgraphCypher::TRANSFORM:
      case MemgraphCypher::TRIGGER:
      case MemgraphCypher::TRIGGERS:
      case MemgraphCypher::UNCOMMITTED:
      case MemgraphCypher::UNLOCK:
      case MemgraphCypher::UPDATE:
      case MemgraphCypher::USER:
      case MemgraphCypher::USERS:
      case MemgraphCypher::VERSION:
      case MemgraphCypher::ALL:
      case MemgraphCypher::AND:
      case MemgraphCypher::ANY:
      case MemgraphCypher::AS:
      case MemgraphCypher::ASC:
      case MemgraphCypher::ASCENDING:
      case MemgraphCypher::ASSERT:
      case MemgraphCypher::BFS:
      case MemgraphCypher::BY:
      case MemgraphCypher::CALL:
      case MemgraphCypher::CASE:
      case MemgraphCypher::CONSTRAINT:
      case MemgraphCypher::CONTAINS:
      case MemgraphCypher::COUNT:
      case MemgraphCypher::CREATE:
      case MemgraphCypher::CYPHERNULL:
      case MemgraphCypher::DELETE:
      case MemgraphCypher::DESC:
      case MemgraphCypher::DESCENDING:
      case MemgraphCypher::DETACH:
      case MemgraphCypher::DISTINCT:
      case MemgraphCypher::ELSE:
      case MemgraphCypher::END:
      case MemgraphCypher::ENDS:
      case MemgraphCypher::EXISTS:
      case MemgraphCypher::EXPLAIN:
      case MemgraphCypher::EXTRACT:
      case MemgraphCypher::FALSE:
      case MemgraphCypher::FILTER:
      case MemgraphCypher::IN:
      case MemgraphCypher::INDEX:
      case MemgraphCypher::INFO:
      case MemgraphCypher::IS:
      case MemgraphCypher::KEY:
      case MemgraphCypher::LIMIT:
      case MemgraphCypher::L_SKIP:
      case MemgraphCypher::MATCH:
      case MemgraphCypher::MERGE:
      case MemgraphCypher::NODE:
      case MemgraphCypher::NONE:
      case MemgraphCypher::NOT:
      case MemgraphCypher::ON:
      case MemgraphCypher::OPTIONAL:
      case MemgraphCypher::OR:
      case MemgraphCypher::ORDER:
      case MemgraphCypher::PROCEDURE:
      case MemgraphCypher::PROFILE:
      case MemgraphCypher::QUERY:
      case MemgraphCypher::REDUCE:
      case MemgraphCypher::REMOVE:
      case MemgraphCypher::RETURN:
      case MemgraphCypher::SET:
      case MemgraphCypher::SHOW:
      case MemgraphCypher::SINGLE:
      case MemgraphCypher::STARTS:
      case MemgraphCypher::STORAGE:
      case MemgraphCypher::THEN:
      case MemgraphCypher::TRUE:
      case MemgraphCypher::TT:
      case MemgraphCypher::UNION:
      case MemgraphCypher::UNIQUE:
      case MemgraphCypher::UNWIND:
      case MemgraphCypher::WHEN:
      case MemgraphCypher::WHERE:
      case MemgraphCypher::WITH:
      case MemgraphCypher::WSHORTEST:
      case MemgraphCypher::XOR:
      case MemgraphCypher::YIELD:
      case MemgraphCypher::UnescapedSymbolicName:
      case MemgraphCypher::EscapedSymbolicName: {
        setState(1838);
        symbolicName();
        break;
      }

      case MemgraphCypher::DecimalLiteral: {
        setState(1839);
        match(MemgraphCypher::DecimalLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyExpressionContext ------------------------------------------------------------------

MemgraphCypher::PropertyExpressionContext::PropertyExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::AtomContext* MemgraphCypher::PropertyExpressionContext::atom() {
  return getRuleContext<MemgraphCypher::AtomContext>(0);
}

std::vector<MemgraphCypher::PropertyLookupContext *> MemgraphCypher::PropertyExpressionContext::propertyLookup() {
  return getRuleContexts<MemgraphCypher::PropertyLookupContext>();
}

MemgraphCypher::PropertyLookupContext* MemgraphCypher::PropertyExpressionContext::propertyLookup(size_t i) {
  return getRuleContext<MemgraphCypher::PropertyLookupContext>(i);
}


size_t MemgraphCypher::PropertyExpressionContext::getRuleIndex() const {
  return MemgraphCypher::RulePropertyExpression;
}

void MemgraphCypher::PropertyExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyExpression(this);
}

void MemgraphCypher::PropertyExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyExpression(this);
}


antlrcpp::Any MemgraphCypher::PropertyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPropertyExpression(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PropertyExpressionContext* MemgraphCypher::propertyExpression() {
  PropertyExpressionContext *_localctx = _tracker.createInstance<PropertyExpressionContext>(_ctx, getState());
  enterRule(_localctx, 362, MemgraphCypher::RulePropertyExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1842);
    atom();
    setState(1844); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1843);
      propertyLookup();
      setState(1846); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MemgraphCypher::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyKeyNameContext ------------------------------------------------------------------

MemgraphCypher::PropertyKeyNameContext::PropertyKeyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MemgraphCypher::SymbolicNameContext* MemgraphCypher::PropertyKeyNameContext::symbolicName() {
  return getRuleContext<MemgraphCypher::SymbolicNameContext>(0);
}


size_t MemgraphCypher::PropertyKeyNameContext::getRuleIndex() const {
  return MemgraphCypher::RulePropertyKeyName;
}

void MemgraphCypher::PropertyKeyNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyKeyName(this);
}

void MemgraphCypher::PropertyKeyNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyKeyName(this);
}


antlrcpp::Any MemgraphCypher::PropertyKeyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitPropertyKeyName(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::PropertyKeyNameContext* MemgraphCypher::propertyKeyName() {
  PropertyKeyNameContext *_localctx = _tracker.createInstance<PropertyKeyNameContext>(_ctx, getState());
  enterRule(_localctx, 364, MemgraphCypher::RulePropertyKeyName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1848);
    symbolicName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerLiteralContext ------------------------------------------------------------------

MemgraphCypher::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::IntegerLiteralContext::DecimalLiteral() {
  return getToken(MemgraphCypher::DecimalLiteral, 0);
}

tree::TerminalNode* MemgraphCypher::IntegerLiteralContext::OctalLiteral() {
  return getToken(MemgraphCypher::OctalLiteral, 0);
}

tree::TerminalNode* MemgraphCypher::IntegerLiteralContext::HexadecimalLiteral() {
  return getToken(MemgraphCypher::HexadecimalLiteral, 0);
}


size_t MemgraphCypher::IntegerLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleIntegerLiteral;
}

void MemgraphCypher::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}

void MemgraphCypher::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}


antlrcpp::Any MemgraphCypher::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::IntegerLiteralContext* MemgraphCypher::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 366, MemgraphCypher::RuleIntegerLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1850);
    _la = _input->LA(1);
    if (!(((((_la - 196) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 196)) & ((1ULL << (MemgraphCypher::DecimalLiteral - 196))
      | (1ULL << (MemgraphCypher::OctalLiteral - 196))
      | (1ULL << (MemgraphCypher::HexadecimalLiteral - 196)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateIndexContext ------------------------------------------------------------------

MemgraphCypher::CreateIndexContext::CreateIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::INDEX() {
  return getToken(MemgraphCypher::INDEX, 0);
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::COLON() {
  return getToken(MemgraphCypher::COLON, 0);
}

MemgraphCypher::LabelNameContext* MemgraphCypher::CreateIndexContext::labelName() {
  return getRuleContext<MemgraphCypher::LabelNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

MemgraphCypher::PropertyKeyNameContext* MemgraphCypher::CreateIndexContext::propertyKeyName() {
  return getRuleContext<MemgraphCypher::PropertyKeyNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::CreateIndexContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}


size_t MemgraphCypher::CreateIndexContext::getRuleIndex() const {
  return MemgraphCypher::RuleCreateIndex;
}

void MemgraphCypher::CreateIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateIndex(this);
}

void MemgraphCypher::CreateIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateIndex(this);
}


antlrcpp::Any MemgraphCypher::CreateIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCreateIndex(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CreateIndexContext* MemgraphCypher::createIndex() {
  CreateIndexContext *_localctx = _tracker.createInstance<CreateIndexContext>(_ctx, getState());
  enterRule(_localctx, 368, MemgraphCypher::RuleCreateIndex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1852);
    match(MemgraphCypher::CREATE);
    setState(1853);
    match(MemgraphCypher::INDEX);
    setState(1854);
    match(MemgraphCypher::ON);
    setState(1855);
    match(MemgraphCypher::COLON);
    setState(1856);
    labelName();
    setState(1861);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::LPAREN) {
      setState(1857);
      match(MemgraphCypher::LPAREN);
      setState(1858);
      propertyKeyName();
      setState(1859);
      match(MemgraphCypher::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropIndexContext ------------------------------------------------------------------

MemgraphCypher::DropIndexContext::DropIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::DROP() {
  return getToken(MemgraphCypher::DROP, 0);
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::INDEX() {
  return getToken(MemgraphCypher::INDEX, 0);
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::COLON() {
  return getToken(MemgraphCypher::COLON, 0);
}

MemgraphCypher::LabelNameContext* MemgraphCypher::DropIndexContext::labelName() {
  return getRuleContext<MemgraphCypher::LabelNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::LPAREN() {
  return getToken(MemgraphCypher::LPAREN, 0);
}

MemgraphCypher::PropertyKeyNameContext* MemgraphCypher::DropIndexContext::propertyKeyName() {
  return getRuleContext<MemgraphCypher::PropertyKeyNameContext>(0);
}

tree::TerminalNode* MemgraphCypher::DropIndexContext::RPAREN() {
  return getToken(MemgraphCypher::RPAREN, 0);
}


size_t MemgraphCypher::DropIndexContext::getRuleIndex() const {
  return MemgraphCypher::RuleDropIndex;
}

void MemgraphCypher::DropIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropIndex(this);
}

void MemgraphCypher::DropIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropIndex(this);
}


antlrcpp::Any MemgraphCypher::DropIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDropIndex(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DropIndexContext* MemgraphCypher::dropIndex() {
  DropIndexContext *_localctx = _tracker.createInstance<DropIndexContext>(_ctx, getState());
  enterRule(_localctx, 370, MemgraphCypher::RuleDropIndex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1863);
    match(MemgraphCypher::DROP);
    setState(1864);
    match(MemgraphCypher::INDEX);
    setState(1865);
    match(MemgraphCypher::ON);
    setState(1866);
    match(MemgraphCypher::COLON);
    setState(1867);
    labelName();
    setState(1872);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MemgraphCypher::LPAREN) {
      setState(1868);
      match(MemgraphCypher::LPAREN);
      setState(1869);
      propertyKeyName();
      setState(1870);
      match(MemgraphCypher::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleLiteralContext ------------------------------------------------------------------

MemgraphCypher::DoubleLiteralContext::DoubleLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::DoubleLiteralContext::FloatingLiteral() {
  return getToken(MemgraphCypher::FloatingLiteral, 0);
}


size_t MemgraphCypher::DoubleLiteralContext::getRuleIndex() const {
  return MemgraphCypher::RuleDoubleLiteral;
}

void MemgraphCypher::DoubleLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoubleLiteral(this);
}

void MemgraphCypher::DoubleLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoubleLiteral(this);
}


antlrcpp::Any MemgraphCypher::DoubleLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitDoubleLiteral(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::DoubleLiteralContext* MemgraphCypher::doubleLiteral() {
  DoubleLiteralContext *_localctx = _tracker.createInstance<DoubleLiteralContext>(_ctx, getState());
  enterRule(_localctx, 372, MemgraphCypher::RuleDoubleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1874);
    match(MemgraphCypher::FloatingLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CypherKeywordContext ------------------------------------------------------------------

MemgraphCypher::CypherKeywordContext::CypherKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ALL() {
  return getToken(MemgraphCypher::ALL, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::AND() {
  return getToken(MemgraphCypher::AND, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ANY() {
  return getToken(MemgraphCypher::ANY, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::AS() {
  return getToken(MemgraphCypher::AS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ASC() {
  return getToken(MemgraphCypher::ASC, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ASCENDING() {
  return getToken(MemgraphCypher::ASCENDING, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ASSERT() {
  return getToken(MemgraphCypher::ASSERT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::BFS() {
  return getToken(MemgraphCypher::BFS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::BY() {
  return getToken(MemgraphCypher::BY, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CALL() {
  return getToken(MemgraphCypher::CALL, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CASE() {
  return getToken(MemgraphCypher::CASE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CONSTRAINT() {
  return getToken(MemgraphCypher::CONSTRAINT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CONTAINS() {
  return getToken(MemgraphCypher::CONTAINS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::COUNT() {
  return getToken(MemgraphCypher::COUNT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CREATE() {
  return getToken(MemgraphCypher::CREATE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::CYPHERNULL() {
  return getToken(MemgraphCypher::CYPHERNULL, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::DELETE() {
  return getToken(MemgraphCypher::DELETE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::DESC() {
  return getToken(MemgraphCypher::DESC, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::DESCENDING() {
  return getToken(MemgraphCypher::DESCENDING, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::DETACH() {
  return getToken(MemgraphCypher::DETACH, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::DISTINCT() {
  return getToken(MemgraphCypher::DISTINCT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ELSE() {
  return getToken(MemgraphCypher::ELSE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::END() {
  return getToken(MemgraphCypher::END, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ENDS() {
  return getToken(MemgraphCypher::ENDS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::EXISTS() {
  return getToken(MemgraphCypher::EXISTS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::EXPLAIN() {
  return getToken(MemgraphCypher::EXPLAIN, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::EXTRACT() {
  return getToken(MemgraphCypher::EXTRACT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::FALSE() {
  return getToken(MemgraphCypher::FALSE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::FILTER() {
  return getToken(MemgraphCypher::FILTER, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::FROM() {
  return getToken(MemgraphCypher::FROM, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::IN() {
  return getToken(MemgraphCypher::IN, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::INDEX() {
  return getToken(MemgraphCypher::INDEX, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::INFO() {
  return getToken(MemgraphCypher::INFO, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::IS() {
  return getToken(MemgraphCypher::IS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::KEY() {
  return getToken(MemgraphCypher::KEY, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::LIMIT() {
  return getToken(MemgraphCypher::LIMIT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::L_SKIP() {
  return getToken(MemgraphCypher::L_SKIP, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::MATCH() {
  return getToken(MemgraphCypher::MATCH, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::MERGE() {
  return getToken(MemgraphCypher::MERGE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::NODE() {
  return getToken(MemgraphCypher::NODE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::NONE() {
  return getToken(MemgraphCypher::NONE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::NOT() {
  return getToken(MemgraphCypher::NOT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ON() {
  return getToken(MemgraphCypher::ON, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::OPTIONAL() {
  return getToken(MemgraphCypher::OPTIONAL, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::OR() {
  return getToken(MemgraphCypher::OR, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::ORDER() {
  return getToken(MemgraphCypher::ORDER, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::PROCEDURE() {
  return getToken(MemgraphCypher::PROCEDURE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::PROFILE() {
  return getToken(MemgraphCypher::PROFILE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::QUERY() {
  return getToken(MemgraphCypher::QUERY, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::REDUCE() {
  return getToken(MemgraphCypher::REDUCE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::REMOVE() {
  return getToken(MemgraphCypher::REMOVE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::RETURN() {
  return getToken(MemgraphCypher::RETURN, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::SET() {
  return getToken(MemgraphCypher::SET, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::SHOW() {
  return getToken(MemgraphCypher::SHOW, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::SINGLE() {
  return getToken(MemgraphCypher::SINGLE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::STARTS() {
  return getToken(MemgraphCypher::STARTS, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::STORAGE() {
  return getToken(MemgraphCypher::STORAGE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::THEN() {
  return getToken(MemgraphCypher::THEN, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::TO() {
  return getToken(MemgraphCypher::TO, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::TRUE() {
  return getToken(MemgraphCypher::TRUE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::TT() {
  return getToken(MemgraphCypher::TT, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::UNION() {
  return getToken(MemgraphCypher::UNION, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::UNIQUE() {
  return getToken(MemgraphCypher::UNIQUE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::UNWIND() {
  return getToken(MemgraphCypher::UNWIND, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::WHEN() {
  return getToken(MemgraphCypher::WHEN, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::WHERE() {
  return getToken(MemgraphCypher::WHERE, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::WITH() {
  return getToken(MemgraphCypher::WITH, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::WSHORTEST() {
  return getToken(MemgraphCypher::WSHORTEST, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::XOR() {
  return getToken(MemgraphCypher::XOR, 0);
}

tree::TerminalNode* MemgraphCypher::CypherKeywordContext::YIELD() {
  return getToken(MemgraphCypher::YIELD, 0);
}


size_t MemgraphCypher::CypherKeywordContext::getRuleIndex() const {
  return MemgraphCypher::RuleCypherKeyword;
}

void MemgraphCypher::CypherKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCypherKeyword(this);
}

void MemgraphCypher::CypherKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MemgraphCypherListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCypherKeyword(this);
}


antlrcpp::Any MemgraphCypher::CypherKeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MemgraphCypherVisitor*>(visitor))
    return parserVisitor->visitCypherKeyword(this);
  else
    return visitor->visitChildren(this);
}

MemgraphCypher::CypherKeywordContext* MemgraphCypher::cypherKeyword() {
  CypherKeywordContext *_localctx = _tracker.createInstance<CypherKeywordContext>(_ctx, getState());
  enterRule(_localctx, 374, MemgraphCypher::RuleCypherKeyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1876);
    _la = _input->LA(1);
    if (!(_la == MemgraphCypher::FROM || ((((_la - 77) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 77)) & ((1ULL << (MemgraphCypher::TO - 77))
      | (1ULL << (MemgraphCypher::ALL - 77))
      | (1ULL << (MemgraphCypher::AND - 77))
      | (1ULL << (MemgraphCypher::ANY - 77))
      | (1ULL << (MemgraphCypher::AS - 77))
      | (1ULL << (MemgraphCypher::ASC - 77))
      | (1ULL << (MemgraphCypher::ASCENDING - 77))
      | (1ULL << (MemgraphCypher::ASSERT - 77))
      | (1ULL << (MemgraphCypher::BFS - 77))
      | (1ULL << (MemgraphCypher::BY - 77))
      | (1ULL << (MemgraphCypher::CALL - 77))
      | (1ULL << (MemgraphCypher::CASE - 77))
      | (1ULL << (MemgraphCypher::CONSTRAINT - 77))
      | (1ULL << (MemgraphCypher::CONTAINS - 77))
      | (1ULL << (MemgraphCypher::COUNT - 77))
      | (1ULL << (MemgraphCypher::CREATE - 77))
      | (1ULL << (MemgraphCypher::CYPHERNULL - 77))
      | (1ULL << (MemgraphCypher::DELETE - 77))
      | (1ULL << (MemgraphCypher::DESC - 77)))) != 0) || ((((_la - 141) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 141)) & ((1ULL << (MemgraphCypher::DESCENDING - 141))
      | (1ULL << (MemgraphCypher::DETACH - 141))
      | (1ULL << (MemgraphCypher::DISTINCT - 141))
      | (1ULL << (MemgraphCypher::ELSE - 141))
      | (1ULL << (MemgraphCypher::END - 141))
      | (1ULL << (MemgraphCypher::ENDS - 141))
      | (1ULL << (MemgraphCypher::EXISTS - 141))
      | (1ULL << (MemgraphCypher::EXPLAIN - 141))
      | (1ULL << (MemgraphCypher::EXTRACT - 141))
      | (1ULL << (MemgraphCypher::FALSE - 141))
      | (1ULL << (MemgraphCypher::FILTER - 141))
      | (1ULL << (MemgraphCypher::IN - 141))
      | (1ULL << (MemgraphCypher::INDEX - 141))
      | (1ULL << (MemgraphCypher::INFO - 141))
      | (1ULL << (MemgraphCypher::IS - 141))
      | (1ULL << (MemgraphCypher::KEY - 141))
      | (1ULL << (MemgraphCypher::LIMIT - 141))
      | (1ULL << (MemgraphCypher::L_SKIP - 141))
      | (1ULL << (MemgraphCypher::MATCH - 141))
      | (1ULL << (MemgraphCypher::MERGE - 141))
      | (1ULL << (MemgraphCypher::NODE - 141))
      | (1ULL << (MemgraphCypher::NONE - 141))
      | (1ULL << (MemgraphCypher::NOT - 141))
      | (1ULL << (MemgraphCypher::ON - 141))
      | (1ULL << (MemgraphCypher::OPTIONAL - 141))
      | (1ULL << (MemgraphCypher::OR - 141))
      | (1ULL << (MemgraphCypher::ORDER - 141))
      | (1ULL << (MemgraphCypher::PROCEDURE - 141))
      | (1ULL << (MemgraphCypher::PROFILE - 141))
      | (1ULL << (MemgraphCypher::QUERY - 141))
      | (1ULL << (MemgraphCypher::REDUCE - 141))
      | (1ULL << (MemgraphCypher::REMOVE - 141))
      | (1ULL << (MemgraphCypher::RETURN - 141))
      | (1ULL << (MemgraphCypher::SET - 141))
      | (1ULL << (MemgraphCypher::SHOW - 141))
      | (1ULL << (MemgraphCypher::SINGLE - 141))
      | (1ULL << (MemgraphCypher::STARTS - 141))
      | (1ULL << (MemgraphCypher::STORAGE - 141))
      | (1ULL << (MemgraphCypher::THEN - 141))
      | (1ULL << (MemgraphCypher::TRUE - 141))
      | (1ULL << (MemgraphCypher::TT - 141))
      | (1ULL << (MemgraphCypher::UNION - 141))
      | (1ULL << (MemgraphCypher::UNIQUE - 141))
      | (1ULL << (MemgraphCypher::UNWIND - 141))
      | (1ULL << (MemgraphCypher::WHEN - 141))
      | (1ULL << (MemgraphCypher::WHERE - 141))
      | (1ULL << (MemgraphCypher::WITH - 141))
      | (1ULL << (MemgraphCypher::WSHORTEST - 141))
      | (1ULL << (MemgraphCypher::XOR - 141))
      | (1ULL << (MemgraphCypher::YIELD - 141)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MemgraphCypher::_decisionToDFA;
atn::PredictionContextCache MemgraphCypher::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MemgraphCypher::_atn;
std::vector<uint16_t> MemgraphCypher::_serializedATN;

std::vector<std::string> MemgraphCypher::_ruleNames = {
  "memgraphCypherKeyword", "symbolicName", "query", "authQuery", "replicationQuery", 
  "triggerQuery", "clause", "streamQuery", "settingQuery", "loadCsv", "csvFile", 
  "delimiter", "quote", "rowVar", "userOrRoleName", "createRole", "dropRole", 
  "showRoles", "createUser", "setPassword", "dropUser", "showUsers", "setRole", 
  "clearRole", "grantPrivilege", "denyPrivilege", "revokePrivilege", "privilege", 
  "privilegeList", "showPrivileges", "showRoleForUser", "showUsersForRole", 
  "dumpQuery", "setReplicationRole", "showReplicationRole", "replicaName", 
  "socketAddress", "registerReplica", "dropReplica", "showReplicas", "lockPathQuery", 
  "freeMemoryQuery", "triggerName", "triggerStatement", "emptyVertex", "emptyEdge", 
  "createTrigger", "dropTrigger", "showTriggers", "isolationLevel", "isolationLevelScope", 
  "isolationLevelQuery", "createSnapshotQuery", "streamName", "symbolicNameWithMinus", 
  "symbolicNameWithDotsAndMinus", "symbolicTopicNames", "topicNames", "commonCreateStreamConfig", 
  "createStream", "configKeyValuePair", "configMap", "kafkaCreateStreamConfig", 
  "kafkaCreateStream", "pulsarCreateStreamConfig", "pulsarCreateStream", 
  "dropStream", "startStream", "startAllStreams", "stopStream", "stopAllStreams", 
  "showStreams", "checkStream", "settingName", "settingValue", "setSetting", 
  "showSetting", "showSettings", "versionQuery", "snapshotQuery", "cypher", 
  "statement", "constraintQuery", "constraint", "constraintPropertyList", 
  "storageInfo", "indexInfo", "constraintInfo", "infoQuery", "explainQuery", 
  "profileQuery", "cypherQuery", "indexQuery", "singleQuery", "cypherUnion", 
  "cypherMatch", "tt", "vt", "unwind", "merge", "mergeAction", "create", 
  "set", "setItem", "cypherDelete", "remove", "removeItem", "with", "cypherReturn", 
  "callProcedure", "procedureName", "yieldProcedureResults", "memoryLimit", 
  "queryMemoryLimit", "procedureMemoryLimit", "procedureResult", "returnBody", 
  "returnItems", "returnItem", "order", "skip", "limit", "sortItem", "where", 
  "pattern", "patternPart", "anonymousPatternPart", "patternElement", "nodePattern", 
  "patternElementChain", "relationshipPattern", "leftArrowHead", "rightArrowHead", 
  "dash", "relationshipDetail", "relationshipLambda", "variableExpansion", 
  "properties", "relationshipTypes", "nodeLabels", "nodeLabel", "labelName", 
  "relTypeName", "expression", "expression12", "expression11", "expression10", 
  "expression9", "expression8", "expression7", "expression6", "expression5", 
  "expression4", "expression3a", "stringAndNullOperators", "expression3b", 
  "listIndexingOrSlicing", "expression2a", "expression2b", "atom", "literal", 
  "booleanLiteral", "listLiteral", "partialComparisonExpression", "parenthesizedExpression", 
  "relationshipsPattern", "filterExpression", "reduceExpression", "extractExpression", 
  "idInColl", "functionInvocation", "functionName", "listComprehension", 
  "patternComprehension", "propertyLookup", "caseExpression", "caseAlternatives", 
  "variable", "numberLiteral", "mapLiteral", "parameter", "propertyExpression", 
  "propertyKeyName", "integerLiteral", "createIndex", "dropIndex", "doubleLiteral", 
  "cypherKeyword"
};

std::vector<std::string> MemgraphCypher::_literalNames = {
  "", "'_'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "'('", "')'", "'['", "']'", "'{'", "'}'", "','", "'.'", "'..'", 
  "':'", "';'", "'$'", "'|'", "'='", "'<'", "'>'", "'<='", "'>='", "'<>'", 
  "'!='", "'=~'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'+='"
};

std::vector<std::string> MemgraphCypher::_symbolicNames = {
  "", "UNDERSCORE", "AFTER", "ALTER", "ASYNC", "AUTH", "BAD", "BATCH_INTERVAL", 
  "BATCH_LIMIT", "BATCH_SIZE", "BEFORE", "BOOTSTRAP_SERVERS", "CHECK", "CLEAR", 
  "COMMIT", "COMMITTED", "CONFIG", "CONFIGS", "CONSUMER_GROUP", "CREDENTIALS", 
  "CSV", "DATA", "DELIMITER", "DATABASE", "DENY", "DIRECTORY", "DROP", "DUMP", 
  "DURABILITY", "EXECUTE", "FOR", "FREE", "FREE_MEMORY", "FROM", "GLOBAL", 
  "GRANT", "GRANTS", "HEADER", "IDENTIFIED", "IGNORE", "ISOLATION", "KAFKA", 
  "LEVEL", "LOAD", "LOCK", "MAIN", "MODE", "MODULE_READ", "MODULE_WRITE", 
  "NEXT", "NO", "PASSWORD", "PORT", "PRIVILEGES", "PULSAR", "READ", "READ_FILE", 
  "REGISTER", "REPLICA", "REPLICAS", "REPLICATION", "REVOKE", "ROLE", "ROLES", 
  "QUOTE", "SERVICE_URL", "SESSION", "SETTING", "SETTINGS", "SNAPSHOT", 
  "START", "STATS", "STOP", "STREAM", "STREAMS", "SYNC", "TIMEOUT", "TO", 
  "TOPICS", "TRANSACTION", "TRANSFORM", "TRIGGER", "TRIGGERS", "UNCOMMITTED", 
  "UNLOCK", "UPDATE", "USER", "USERS", "VERSION", "WEBSOCKET", "Skipped", 
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "COMMA", "DOT", 
  "DOTS", "COLON", "SEMICOLON", "DOLLAR", "PIPE", "EQ", "LT", "GT", "LTE", 
  "GTE", "NEQ1", "NEQ2", "SIM", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", 
  "CARET", "PLUS_EQ", "LeftArrowHeadPart", "RightArrowHeadPart", "DashPart", 
  "ALL", "AND", "ANY", "AS", "ASC", "ASCENDING", "ASSERT", "BFS", "BY", 
  "CALL", "CASE", "COALESCE", "CONSTRAINT", "CONTAINS", "COUNT", "CREATE", 
  "CYPHERNULL", "DELETE", "DESC", "DESCENDING", "DETACH", "DISTINCT", "ELSE", 
  "END", "ENDS", "EXISTS", "EXPLAIN", "EXTRACT", "FALSE", "FILTER", "IN", 
  "INDEX", "INFO", "IS", "KB", "KEY", "LIMIT", "L_SKIP", "MATCH", "MB", 
  "MEMORY", "MERGE", "NODE", "NONE", "NOT", "ON", "OPTIONAL", "OR", "ORDER", 
  "PROCEDURE", "PROFILE", "QUERY", "REDUCE", "REMOVE", "RETURN", "SET", 
  "SHOW", "SINGLE", "STARTS", "STORAGE", "THEN", "TRUE", "TT", "UNION", 
  "UNIQUE", "UNLIMITED", "UNWIND", "WHEN", "WHERE", "WITH", "WSHORTEST", 
  "XOR", "YIELD", "StringLiteral", "DecimalLiteral", "OctalLiteral", "HexadecimalLiteral", 
  "FloatingLiteral", "UnescapedSymbolicName", "EscapedSymbolicName", "IdentifierStart", 
  "IdentifierPart", "VT", "From"
};

dfa::Vocabulary MemgraphCypher::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MemgraphCypher::_tokenNames;

MemgraphCypher::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xcf, 0x759, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 0x73, 0x4, 0x74, 
       0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 0x4, 0x77, 
       0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 0x7a, 
       0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
       0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 
       0x9, 0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 
       0x9, 0x83, 0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 
       0x9, 0x86, 0x4, 0x87, 0x9, 0x87, 0x4, 0x88, 0x9, 0x88, 0x4, 0x89, 
       0x9, 0x89, 0x4, 0x8a, 0x9, 0x8a, 0x4, 0x8b, 0x9, 0x8b, 0x4, 0x8c, 
       0x9, 0x8c, 0x4, 0x8d, 0x9, 0x8d, 0x4, 0x8e, 0x9, 0x8e, 0x4, 0x8f, 
       0x9, 0x8f, 0x4, 0x90, 0x9, 0x90, 0x4, 0x91, 0x9, 0x91, 0x4, 0x92, 
       0x9, 0x92, 0x4, 0x93, 0x9, 0x93, 0x4, 0x94, 0x9, 0x94, 0x4, 0x95, 
       0x9, 0x95, 0x4, 0x96, 0x9, 0x96, 0x4, 0x97, 0x9, 0x97, 0x4, 0x98, 
       0x9, 0x98, 0x4, 0x99, 0x9, 0x99, 0x4, 0x9a, 0x9, 0x9a, 0x4, 0x9b, 
       0x9, 0x9b, 0x4, 0x9c, 0x9, 0x9c, 0x4, 0x9d, 0x9, 0x9d, 0x4, 0x9e, 
       0x9, 0x9e, 0x4, 0x9f, 0x9, 0x9f, 0x4, 0xa0, 0x9, 0xa0, 0x4, 0xa1, 
       0x9, 0xa1, 0x4, 0xa2, 0x9, 0xa2, 0x4, 0xa3, 0x9, 0xa3, 0x4, 0xa4, 
       0x9, 0xa4, 0x4, 0xa5, 0x9, 0xa5, 0x4, 0xa6, 0x9, 0xa6, 0x4, 0xa7, 
       0x9, 0xa7, 0x4, 0xa8, 0x9, 0xa8, 0x4, 0xa9, 0x9, 0xa9, 0x4, 0xaa, 
       0x9, 0xaa, 0x4, 0xab, 0x9, 0xab, 0x4, 0xac, 0x9, 0xac, 0x4, 0xad, 
       0x9, 0xad, 0x4, 0xae, 0x9, 0xae, 0x4, 0xaf, 0x9, 0xaf, 0x4, 0xb0, 
       0x9, 0xb0, 0x4, 0xb1, 0x9, 0xb1, 0x4, 0xb2, 0x9, 0xb2, 0x4, 0xb3, 
       0x9, 0xb3, 0x4, 0xb4, 0x9, 0xb4, 0x4, 0xb5, 0x9, 0xb5, 0x4, 0xb6, 
       0x9, 0xb6, 0x4, 0xb7, 0x9, 0xb7, 0x4, 0xb8, 0x9, 0xb8, 0x4, 0xb9, 
       0x9, 0xb9, 0x4, 0xba, 0x9, 0xba, 0x4, 0xbb, 0x9, 0xbb, 0x4, 0xbc, 
       0x9, 0xbc, 0x4, 0xbd, 0x9, 0xbd, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x1c9, 0xa, 0x2, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1ce, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1e2, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x1f3, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1fa, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x5, 0x7, 0x1ff, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x5, 0x8, 0x20c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
       0x216, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x21b, 0xa, 
       0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x225, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x5, 0xb, 0x229, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x22d, 0xa, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
       0x14, 0x24d, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x26d, 0xa, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 
       0x1b, 0x276, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x27f, 0xa, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x289, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
       0x28c, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x2a8, 0xa, 0x23, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x2b9, 0xa, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
       0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 
       0x2c, 0x3, 0x2d, 0x7, 0x2d, 0x2cf, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
       0x2d2, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2e1, 0xa, 0x30, 0x3, 0x30, 
       0x5, 0x30, 0x2e4, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x2f8, 0xa, 0x33, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
       0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x30b, 0xa, 
       0x38, 0xc, 0x38, 0xe, 0x38, 0x30e, 0xb, 0x38, 0x3, 0x39, 0x3, 0x39, 
       0x3, 0x39, 0x7, 0x39, 0x313, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x316, 
       0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x31b, 0xa, 
       0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x31e, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
       0x5, 0x3b, 0x322, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
       0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x32a, 0xa, 0x3c, 0x3, 0x3d, 
       0x3, 0x3d, 0x5, 0x3d, 0x32e, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 
       0x3f, 0x338, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x33b, 0xb, 0x3f, 0x5, 
       0x3f, 0x33d, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 
       0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
       0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x34c, 0xa, 0x40, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x353, 
       0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x356, 0xb, 0x41, 0x3, 0x42, 0x3, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x35d, 0xa, 0x42, 
       0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 
       0x364, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x367, 0xb, 0x43, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 
       0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
       0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x385, 0xa, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x389, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 
       0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
       0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
       0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
       0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
       0x3, 0x52, 0x5, 0x52, 0x3a6, 0xa, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
       0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
       0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x3d3, 
       0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 
       0x3, 0x56, 0x7, 0x56, 0x3db, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x3de, 
       0xb, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 
       0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x3ed, 0xa, 0x5a, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 
       0x5d, 0x7, 0x5d, 0x3f7, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x3fa, 0xb, 
       0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3fd, 0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 
       0x5, 0x5e, 0x401, 0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x7, 0x5f, 0x405, 
       0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 0x408, 0xb, 0x5f, 0x3, 0x60, 0x3, 
       0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x40f, 0xa, 0x60, 
       0x3, 0x61, 0x5, 0x61, 0x412, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 
       0x61, 0x5, 0x61, 0x417, 0xa, 0x61, 0x3, 0x61, 0x5, 0x61, 0x41a, 0xa, 
       0x61, 0x3, 0x61, 0x5, 0x61, 0x41d, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x62, 0x5, 0x62, 0x428, 0xa, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 
       0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 
       0x63, 0x5, 0x63, 0x433, 0xa, 0x63, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
       0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x7, 0x65, 
       0x43d, 0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x440, 0xb, 0x65, 0x3, 0x66, 
       0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x66, 0x5, 0x66, 
       0x448, 0xa, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 
       0x68, 0x3, 0x68, 0x3, 0x68, 0x7, 0x68, 0x451, 0xa, 0x68, 0xc, 0x68, 
       0xe, 0x68, 0x454, 0xb, 0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 
       0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 
       0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x69, 0x5, 
       0x69, 0x465, 0xa, 0x69, 0x3, 0x6a, 0x5, 0x6a, 0x468, 0xa, 0x6a, 0x3, 
       0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 0x46e, 0xa, 0x6a, 
       0xc, 0x6a, 0xe, 0x6a, 0x471, 0xb, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 
       0x6b, 0x3, 0x6b, 0x7, 0x6b, 0x477, 0xa, 0x6b, 0xc, 0x6b, 0xe, 0x6b, 
       0x47a, 0xb, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x5, 
       0x6c, 0x480, 0xa, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x484, 0xa, 
       0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x488, 0xa, 0x6d, 0x3, 0x6e, 
       0x3, 0x6e, 0x5, 0x6e, 0x48c, 0xa, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 
       0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x7, 
       0x6f, 0x496, 0xa, 0x6f, 0xc, 0x6f, 0xe, 0x6f, 0x499, 0xb, 0x6f, 0x5, 
       0x6f, 0x49b, 0xa, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x49f, 0xa, 
       0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x4a2, 0xa, 0x6f, 0x3, 0x70, 0x3, 0x70, 
       0x3, 0x70, 0x7, 0x70, 0x4a7, 0xa, 0x70, 0xc, 0x70, 0xe, 0x70, 0x4aa, 
       0xb, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 
       0x7, 0x71, 0x4b1, 0xa, 0x71, 0xc, 0x71, 0xe, 0x71, 0x4b4, 0xb, 0x71, 
       0x5, 0x71, 0x4b6, 0xa, 0x71, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 
       0x72, 0x3, 0x72, 0x3, 0x72, 0x5, 0x72, 0x4be, 0xa, 0x72, 0x3, 0x73, 
       0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x3, 0x75, 
       0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x5, 0x75, 0x4cb, 0xa, 
       0x75, 0x3, 0x76, 0x3, 0x76, 0x5, 0x76, 0x4cf, 0xa, 0x76, 0x3, 0x76, 
       0x5, 0x76, 0x4d2, 0xa, 0x76, 0x3, 0x76, 0x5, 0x76, 0x4d5, 0xa, 0x76, 
       0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x7, 0x77, 0x4da, 0xa, 0x77, 0xc, 
       0x77, 0xe, 0x77, 0x4dd, 0xb, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 
       0x7, 0x77, 0x4e2, 0xa, 0x77, 0xc, 0x77, 0xe, 0x77, 0x4e5, 0xb, 0x77, 
       0x5, 0x77, 0x4e7, 0xa, 0x77, 0x3, 0x78, 0x3, 0x78, 0x3, 0x78, 0x3, 
       0x78, 0x3, 0x78, 0x5, 0x78, 0x4ee, 0xa, 0x78, 0x3, 0x79, 0x3, 0x79, 
       0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x7, 0x79, 0x4f5, 0xa, 0x79, 0xc, 
       0x79, 0xe, 0x79, 0x4f8, 0xb, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 
       0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7c, 0x3, 0x7c, 0x5, 0x7c, 
       0x502, 0xa, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7e, 0x3, 
       0x7e, 0x3, 0x7e, 0x7, 0x7e, 0x50a, 0xa, 0x7e, 0xc, 0x7e, 0xe, 0x7e, 
       0x50d, 0xb, 0x7e, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 
       0x7f, 0x5, 0x7f, 0x514, 0xa, 0x7f, 0x3, 0x80, 0x3, 0x80, 0x3, 0x81, 
       0x3, 0x81, 0x7, 0x81, 0x51a, 0xa, 0x81, 0xc, 0x81, 0xe, 0x81, 0x51d, 
       0xb, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x5, 0x81, 
       0x523, 0xa, 0x81, 0x3, 0x82, 0x3, 0x82, 0x5, 0x82, 0x527, 0xa, 0x82, 
       0x3, 0x82, 0x5, 0x82, 0x52a, 0xa, 0x82, 0x3, 0x82, 0x5, 0x82, 0x52d, 
       0xa, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 
       0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x5, 0x84, 0x537, 0xa, 0x84, 0x3, 
       0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x5, 
       0x84, 0x53f, 0xa, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 
       0x5, 0x84, 0x545, 0xa, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 
       0x84, 0x3, 0x84, 0x5, 0x84, 0x54c, 0xa, 0x84, 0x3, 0x84, 0x3, 0x84, 
       0x5, 0x84, 0x550, 0xa, 0x84, 0x3, 0x85, 0x3, 0x85, 0x3, 0x86, 0x3, 
       0x86, 0x3, 0x87, 0x3, 0x87, 0x3, 0x88, 0x3, 0x88, 0x5, 0x88, 0x55a, 
       0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x55d, 0xa, 0x88, 0x3, 0x88, 0x5, 
       0x88, 0x560, 0xa, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
       0x3, 0x88, 0x5, 0x88, 0x567, 0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x56a, 
       0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x56d, 0xa, 0x88, 0x3, 0x88, 0x3, 
       0x88, 0x5, 0x88, 0x571, 0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x574, 0xa, 
       0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x5, 0x88, 0x57a, 
       0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x57d, 0xa, 0x88, 0x3, 0x88, 0x5, 
       0x88, 0x580, 0xa, 0x88, 0x3, 0x88, 0x7, 0x88, 0x583, 0xa, 0x88, 0xc, 
       0x88, 0xe, 0x88, 0x586, 0xb, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
       0x5, 0x88, 0x58b, 0xa, 0x88, 0x3, 0x88, 0x5, 0x88, 0x58e, 0xa, 0x88, 
       0x3, 0x88, 0x5, 0x88, 0x591, 0xa, 0x88, 0x3, 0x89, 0x3, 0x89, 0x3, 
       0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 
       0x8a, 0x3, 0x8a, 0x5, 0x8a, 0x59d, 0xa, 0x8a, 0x3, 0x8a, 0x5, 0x8a, 
       0x5a0, 0xa, 0x8a, 0x3, 0x8a, 0x3, 0x8a, 0x5, 0x8a, 0x5a4, 0xa, 0x8a, 
       0x5, 0x8a, 0x5a6, 0xa, 0x8a, 0x3, 0x8b, 0x3, 0x8b, 0x5, 0x8b, 0x5aa, 
       0xa, 0x8b, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8c, 0x5, 0x8c, 
       0x5b0, 0xa, 0x8c, 0x3, 0x8c, 0x7, 0x8c, 0x5b3, 0xa, 0x8c, 0xc, 0x8c, 
       0xe, 0x8c, 0x5b6, 0xb, 0x8c, 0x3, 0x8d, 0x3, 0x8d, 0x7, 0x8d, 0x5ba, 
       0xa, 0x8d, 0xc, 0x8d, 0xe, 0x8d, 0x5bd, 0xb, 0x8d, 0x3, 0x8e, 0x3, 
       0x8e, 0x3, 0x8e, 0x3, 0x8f, 0x3, 0x8f, 0x3, 0x90, 0x3, 0x90, 0x3, 
       0x91, 0x3, 0x91, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 0x7, 0x92, 0x5cb, 
       0xa, 0x92, 0xc, 0x92, 0xe, 0x92, 0x5ce, 0xb, 0x92, 0x3, 0x93, 0x3, 
       0x93, 0x3, 0x93, 0x7, 0x93, 0x5d3, 0xa, 0x93, 0xc, 0x93, 0xe, 0x93, 
       0x5d6, 0xb, 0x93, 0x3, 0x94, 0x3, 0x94, 0x3, 0x94, 0x7, 0x94, 0x5db, 
       0xa, 0x94, 0xc, 0x94, 0xe, 0x94, 0x5de, 0xb, 0x94, 0x3, 0x95, 0x7, 
       0x95, 0x5e1, 0xa, 0x95, 0xc, 0x95, 0xe, 0x95, 0x5e4, 0xb, 0x95, 0x3, 
       0x95, 0x3, 0x95, 0x3, 0x96, 0x3, 0x96, 0x7, 0x96, 0x5ea, 0xa, 0x96, 
       0xc, 0x96, 0xe, 0x96, 0x5ed, 0xb, 0x96, 0x3, 0x97, 0x3, 0x97, 0x3, 
       0x97, 0x3, 0x97, 0x3, 0x97, 0x7, 0x97, 0x5f4, 0xa, 0x97, 0xc, 0x97, 
       0xe, 0x97, 0x5f7, 0xb, 0x97, 0x3, 0x98, 0x3, 0x98, 0x3, 0x98, 0x3, 
       0x98, 0x3, 0x98, 0x3, 0x98, 0x3, 0x98, 0x7, 0x98, 0x600, 0xa, 0x98, 
       0xc, 0x98, 0xe, 0x98, 0x603, 0xb, 0x98, 0x3, 0x99, 0x3, 0x99, 0x3, 
       0x99, 0x7, 0x99, 0x608, 0xa, 0x99, 0xc, 0x99, 0xe, 0x99, 0x60b, 0xb, 
       0x99, 0x3, 0x9a, 0x7, 0x9a, 0x60e, 0xa, 0x9a, 0xc, 0x9a, 0xe, 0x9a, 
       0x611, 0xb, 0x9a, 0x3, 0x9a, 0x3, 0x9a, 0x3, 0x9b, 0x3, 0x9b, 0x7, 
       0x9b, 0x617, 0xa, 0x9b, 0xc, 0x9b, 0xe, 0x9b, 0x61a, 0xb, 0x9b, 0x3, 
       0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 
       0x9c, 0x5, 0x9c, 0x623, 0xa, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 
       0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9c, 0x5, 0x9c, 0x62b, 0xa, 0x9c, 0x3, 
       0x9d, 0x3, 0x9d, 0x7, 0x9d, 0x62f, 0xa, 0x9d, 0xc, 0x9d, 0xe, 0x9d, 
       0x632, 0xb, 0x9d, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 
       0x9e, 0x3, 0x9e, 0x5, 0x9e, 0x63a, 0xa, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 
       0x5, 0x9e, 0x63e, 0xa, 0x9e, 0x3, 0x9e, 0x5, 0x9e, 0x641, 0xa, 0x9e, 
       0x3, 0x9f, 0x3, 0x9f, 0x5, 0x9f, 0x645, 0xa, 0x9f, 0x3, 0xa0, 0x3, 
       0xa0, 0x7, 0xa0, 0x649, 0xa, 0xa0, 0xc, 0xa0, 0xe, 0xa0, 0x64c, 0xb, 
       0xa0, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x7, 
       0xa1, 0x66b, 0xa, 0xa1, 0xc, 0xa1, 0xe, 0xa1, 0x66e, 0xb, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 0xa1, 0x3, 
       0xa1, 0x3, 0xa1, 0x5, 0xa1, 0x68a, 0xa, 0xa1, 0x3, 0xa2, 0x3, 0xa2, 
       0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x3, 0xa2, 0x5, 0xa2, 0x692, 0xa, 
       0xa2, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x3, 
       0xa4, 0x7, 0xa4, 0x69a, 0xa, 0xa4, 0xc, 0xa4, 0xe, 0xa4, 0x69d, 0xb, 
       0xa4, 0x5, 0xa4, 0x69f, 0xa, 0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa5, 
       0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 
       0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa5, 
       0x3, 0xa5, 0x5, 0xa5, 0x6b1, 0xa, 0xa5, 0x3, 0xa6, 0x3, 0xa6, 0x3, 
       0xa6, 0x3, 0xa6, 0x3, 0xa7, 0x3, 0xa7, 0x6, 0xa7, 0x6b9, 0xa, 0xa7, 
       0xd, 0xa7, 0xe, 0xa7, 0x6ba, 0x3, 0xa8, 0x3, 0xa8, 0x5, 0xa8, 0x6bf, 
       0xa, 0xa8, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 
       0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xaa, 0x3, 0xaa, 0x3, 0xaa, 
       0x3, 0xaa, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xac, 
       0x3, 0xac, 0x3, 0xac, 0x5, 0xac, 0x6d4, 0xa, 0xac, 0x3, 0xac, 0x3, 
       0xac, 0x3, 0xac, 0x7, 0xac, 0x6d9, 0xa, 0xac, 0xc, 0xac, 0xe, 0xac, 
       0x6dc, 0xb, 0xac, 0x5, 0xac, 0x6de, 0xa, 0xac, 0x3, 0xac, 0x3, 0xac, 
       0x3, 0xad, 0x3, 0xad, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 
       0x5, 0xae, 0x6e8, 0xa, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xaf, 0x3, 
       0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x5, 0xaf, 0x6f0, 0xa, 0xaf, 0x3, 0xaf, 
       0x3, 0xaf, 0x3, 0xaf, 0x5, 0xaf, 0x6f5, 0xa, 0xaf, 0x3, 0xaf, 0x3, 
       0xaf, 0x3, 0xaf, 0x3, 0xaf, 0x3, 0xb0, 0x3, 0xb0, 0x3, 0xb0, 0x3, 
       0xb1, 0x3, 0xb1, 0x6, 0xb1, 0x700, 0xa, 0xb1, 0xd, 0xb1, 0xe, 0xb1, 
       0x701, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x6, 0xb1, 0x707, 0xa, 0xb1, 
       0xd, 0xb1, 0xe, 0xb1, 0x708, 0x5, 0xb1, 0x70b, 0xa, 0xb1, 0x3, 0xb1, 
       0x3, 0xb1, 0x5, 0xb1, 0x70f, 0xa, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 
       0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb3, 0x3, 
       0xb3, 0x3, 0xb4, 0x3, 0xb4, 0x5, 0xb4, 0x71c, 0xa, 0xb4, 0x3, 0xb5, 
       0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb5, 
       0x3, 0xb5, 0x3, 0xb5, 0x7, 0xb5, 0x727, 0xa, 0xb5, 0xc, 0xb5, 0xe, 
       0xb5, 0x72a, 0xb, 0xb5, 0x5, 0xb5, 0x72c, 0xa, 0xb5, 0x3, 0xb5, 0x3, 
       0xb5, 0x3, 0xb6, 0x3, 0xb6, 0x3, 0xb6, 0x5, 0xb6, 0x733, 0xa, 0xb6, 
       0x3, 0xb7, 0x3, 0xb7, 0x6, 0xb7, 0x737, 0xa, 0xb7, 0xd, 0xb7, 0xe, 
       0xb7, 0x738, 0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb9, 0x3, 0xb9, 0x3, 0xba, 
       0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 
       0x3, 0xba, 0x3, 0xba, 0x5, 0xba, 0x748, 0xa, 0xba, 0x3, 0xbb, 0x3, 
       0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x3, 0xbb, 0x3, 
       0xbb, 0x3, 0xbb, 0x5, 0xbb, 0x753, 0xa, 0xbb, 0x3, 0xbc, 0x3, 0xbc, 
       0x3, 0xbd, 0x3, 0xbd, 0x3, 0xbd, 0x3, 0x2d0, 0x2, 0xbe, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
       0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
       0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
       0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
       0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
       0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 
       0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
       0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 
       0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 
       0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 0xe0, 0xe2, 
       0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 
       0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 0x108, 0x10a, 0x10c, 
       0x10e, 0x110, 0x112, 0x114, 0x116, 0x118, 0x11a, 0x11c, 0x11e, 0x120, 
       0x122, 0x124, 0x126, 0x128, 0x12a, 0x12c, 0x12e, 0x130, 0x132, 0x134, 
       0x136, 0x138, 0x13a, 0x13c, 0x13e, 0x140, 0x142, 0x144, 0x146, 0x148, 
       0x14a, 0x14c, 0x14e, 0x150, 0x152, 0x154, 0x156, 0x158, 0x15a, 0x15c, 
       0x15e, 0x160, 0x162, 0x164, 0x166, 0x168, 0x16a, 0x16c, 0x16e, 0x170, 
       0x172, 0x174, 0x176, 0x178, 0x2, 0x15, 0x4, 0x2, 0x34, 0x34, 0xc1, 
       0xc1, 0x16, 0x2, 0x7, 0x7, 0x12, 0x12, 0x1d, 0x1e, 0x22, 0x22, 0x31, 
       0x32, 0x3a, 0x3a, 0x3e, 0x3e, 0x47, 0x47, 0x49, 0x49, 0x4b, 0x4b, 
       0x53, 0x53, 0x5b, 0x5b, 0x88, 0x88, 0x8b, 0x8b, 0x8d, 0x8d, 0x9b, 
       0x9b, 0xa2, 0xa2, 0xa5, 0xa5, 0xb1, 0xb1, 0xb3, 0xb3, 0x4, 0x2, 0x2f, 
       0x2f, 0x3c, 0x3c, 0x4, 0x2, 0x6, 0x6, 0x4d, 0x4d, 0x4, 0x2, 0x2e, 
       0x2e, 0x56, 0x56, 0x5, 0x2, 0x57, 0x57, 0x8b, 0x8b, 0x8d, 0x8d, 0x4, 
       0x2, 0x4, 0x4, 0xc, 0xc, 0x5, 0x2, 0x24, 0x24, 0x33, 0x33, 0x44, 
       0x44, 0x4, 0x2, 0x1c, 0x1c, 0x8b, 0x8b, 0x4, 0x2, 0x9e, 0x9e, 0xa3, 
       0xa3, 0x4, 0x2, 0x80, 0x81, 0x8e, 0x8f, 0x4, 0x2, 0x6b, 0x6b, 0x79, 
       0x79, 0x4, 0x2, 0x6c, 0x6c, 0x7a, 0x7a, 0x4, 0x2, 0x73, 0x73, 0x7b, 
       0x7b, 0x4, 0x2, 0x83, 0x83, 0xc2, 0xc2, 0x3, 0x2, 0x72, 0x73, 0x4, 
       0x2, 0x98, 0x98, 0xb9, 0xb9, 0x3, 0x2, 0xc6, 0xc8, 0x9, 0x2, 0x23, 
       0x23, 0x4f, 0x4f, 0x7c, 0x86, 0x88, 0x9d, 0x9f, 0xa2, 0xa5, 0xbc, 
       0xbe, 0xc4, 0x2, 0x7e8, 0x2, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1f2, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0xc, 0x1fe, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x215, 0x3, 0x2, 
       0x2, 0x2, 0x12, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x21c, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x231, 0x3, 0x2, 0x2, 0x2, 0x18, 0x233, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x235, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x237, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x239, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23b, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x243, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0x246, 0x3, 0x2, 0x2, 0x2, 0x28, 0x24e, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x255, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x259, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x30, 0x263, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x268, 0x3, 0x2, 0x2, 0x2, 0x34, 0x271, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x283, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x285, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x28d, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x292, 0x3, 0x2, 0x2, 0x2, 0x40, 0x297, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x29f, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x48, 0x2ad, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x2b1, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x50, 0x2c1, 0x3, 0x2, 
       0x2, 0x2, 0x52, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2c8, 0x3, 0x2, 
       0x2, 0x2, 0x56, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2d0, 0x3, 0x2, 
       0x2, 0x2, 0x5a, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2d6, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2ea, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2f7, 0x3, 0x2, 
       0x2, 0x2, 0x66, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2fb, 0x3, 0x2, 
       0x2, 0x2, 0x6a, 0x302, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x305, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x307, 0x3, 0x2, 0x2, 0x2, 0x70, 0x30f, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x317, 0x3, 0x2, 0x2, 0x2, 0x74, 0x321, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x329, 0x3, 0x2, 0x2, 0x2, 0x78, 0x32d, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x333, 0x3, 0x2, 
       0x2, 0x2, 0x7e, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x34d, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x35e, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x368, 0x3, 0x2, 0x2, 0x2, 0x88, 0x36c, 0x3, 0x2, 
       0x2, 0x2, 0x8a, 0x370, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x374, 0x3, 0x2, 
       0x2, 0x2, 0x8e, 0x378, 0x3, 0x2, 0x2, 0x2, 0x90, 0x37c, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x94, 0x38a, 0x3, 0x2, 
       0x2, 0x2, 0x96, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x98, 0x38e, 0x3, 0x2, 
       0x2, 0x2, 0x9a, 0x395, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x39a, 0x3, 0x2, 
       0x2, 0x2, 0x9e, 0x39e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x3a1, 0x3, 0x2, 
       0x2, 0x2, 0xa2, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x3a9, 0x3, 0x2, 
       0x2, 0x2, 0xa6, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x3d2, 0x3, 0x2, 
       0x2, 0x2, 0xaa, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0xac, 0x3df, 0x3, 0x2, 
       0x2, 0x2, 0xae, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x3e5, 0x3, 0x2, 
       0x2, 0x2, 0xb2, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x3ee, 0x3, 0x2, 
       0x2, 0x2, 0xb6, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x3f4, 0x3, 0x2, 
       0x2, 0x2, 0xba, 0x400, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x402, 0x3, 0x2, 
       0x2, 0x2, 0xbe, 0x40e, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x411, 0x3, 0x2, 
       0x2, 0x2, 0xc2, 0x427, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x432, 0x3, 0x2, 
       0x2, 0x2, 0xc6, 0x434, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x439, 0x3, 0x2, 
       0x2, 0x2, 0xca, 0x447, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x449, 0x3, 0x2, 
       0x2, 0x2, 0xce, 0x44c, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x464, 0x3, 0x2, 
       0x2, 0x2, 0xd2, 0x467, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x472, 0x3, 0x2, 
       0x2, 0x2, 0xd6, 0x47f, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x481, 0x3, 0x2, 
       0x2, 0x2, 0xda, 0x489, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x48f, 0x3, 0x2, 
       0x2, 0x2, 0xde, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x4ab, 0x3, 0x2, 
       0x2, 0x2, 0xe2, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x4bf, 0x3, 0x2, 
       0x2, 0x2, 0xe6, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x4ca, 0x3, 0x2, 
       0x2, 0x2, 0xea, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0xec, 0x4e6, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x4ef, 0x3, 0x2, 
       0x2, 0x2, 0xf2, 0x4f9, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x4fc, 0x3, 0x2, 
       0x2, 0x2, 0xf6, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x503, 0x3, 0x2, 
       0x2, 0x2, 0xfa, 0x506, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x513, 0x3, 0x2, 
       0x2, 0x2, 0xfe, 0x515, 0x3, 0x2, 0x2, 0x2, 0x100, 0x522, 0x3, 0x2, 
       0x2, 0x2, 0x102, 0x524, 0x3, 0x2, 0x2, 0x2, 0x104, 0x530, 0x3, 0x2, 
       0x2, 0x2, 0x106, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x108, 0x551, 0x3, 0x2, 
       0x2, 0x2, 0x10a, 0x553, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x555, 0x3, 0x2, 
       0x2, 0x2, 0x10e, 0x590, 0x3, 0x2, 0x2, 0x2, 0x110, 0x592, 0x3, 0x2, 
       0x2, 0x2, 0x112, 0x59a, 0x3, 0x2, 0x2, 0x2, 0x114, 0x5a9, 0x3, 0x2, 
       0x2, 0x2, 0x116, 0x5ab, 0x3, 0x2, 0x2, 0x2, 0x118, 0x5b7, 0x3, 0x2, 
       0x2, 0x2, 0x11a, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x5c1, 0x3, 0x2, 
       0x2, 0x2, 0x11e, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x120, 0x5c5, 0x3, 0x2, 
       0x2, 0x2, 0x122, 0x5c7, 0x3, 0x2, 0x2, 0x2, 0x124, 0x5cf, 0x3, 0x2, 
       0x2, 0x2, 0x126, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x128, 0x5e2, 0x3, 0x2, 
       0x2, 0x2, 0x12a, 0x5e7, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x5ee, 0x3, 0x2, 
       0x2, 0x2, 0x12e, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x130, 0x604, 0x3, 0x2, 
       0x2, 0x2, 0x132, 0x60f, 0x3, 0x2, 0x2, 0x2, 0x134, 0x614, 0x3, 0x2, 
       0x2, 0x2, 0x136, 0x62a, 0x3, 0x2, 0x2, 0x2, 0x138, 0x62c, 0x3, 0x2, 
       0x2, 0x2, 0x13a, 0x640, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x642, 0x3, 0x2, 
       0x2, 0x2, 0x13e, 0x646, 0x3, 0x2, 0x2, 0x2, 0x140, 0x689, 0x3, 0x2, 
       0x2, 0x2, 0x142, 0x691, 0x3, 0x2, 0x2, 0x2, 0x144, 0x693, 0x3, 0x2, 
       0x2, 0x2, 0x146, 0x695, 0x3, 0x2, 0x2, 0x2, 0x148, 0x6b0, 0x3, 0x2, 
       0x2, 0x2, 0x14a, 0x6b2, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x6b6, 0x3, 0x2, 
       0x2, 0x2, 0x14e, 0x6bc, 0x3, 0x2, 0x2, 0x2, 0x150, 0x6c0, 0x3, 0x2, 
       0x2, 0x2, 0x152, 0x6c8, 0x3, 0x2, 0x2, 0x2, 0x154, 0x6cc, 0x3, 0x2, 
       0x2, 0x2, 0x156, 0x6d0, 0x3, 0x2, 0x2, 0x2, 0x158, 0x6e1, 0x3, 0x2, 
       0x2, 0x2, 0x15a, 0x6e3, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x6eb, 0x3, 0x2, 
       0x2, 0x2, 0x15e, 0x6fa, 0x3, 0x2, 0x2, 0x2, 0x160, 0x70a, 0x3, 0x2, 
       0x2, 0x2, 0x162, 0x712, 0x3, 0x2, 0x2, 0x2, 0x164, 0x717, 0x3, 0x2, 
       0x2, 0x2, 0x166, 0x71b, 0x3, 0x2, 0x2, 0x2, 0x168, 0x71d, 0x3, 0x2, 
       0x2, 0x2, 0x16a, 0x72f, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x734, 0x3, 0x2, 
       0x2, 0x2, 0x16e, 0x73a, 0x3, 0x2, 0x2, 0x2, 0x170, 0x73c, 0x3, 0x2, 
       0x2, 0x2, 0x172, 0x73e, 0x3, 0x2, 0x2, 0x2, 0x174, 0x749, 0x3, 0x2, 
       0x2, 0x2, 0x176, 0x754, 0x3, 0x2, 0x2, 0x2, 0x178, 0x756, 0x3, 0x2, 
       0x2, 0x2, 0x17a, 0x1c9, 0x5, 0x178, 0xbd, 0x2, 0x17b, 0x1c9, 0x7, 
       0x4, 0x2, 0x2, 0x17c, 0x1c9, 0x7, 0x5, 0x2, 0x2, 0x17d, 0x1c9, 0x7, 
       0x6, 0x2, 0x2, 0x17e, 0x1c9, 0x7, 0x7, 0x2, 0x2, 0x17f, 0x1c9, 0x7, 
       0x8, 0x2, 0x2, 0x180, 0x1c9, 0x7, 0x9, 0x2, 0x2, 0x181, 0x1c9, 0x7, 
       0xa, 0x2, 0x2, 0x182, 0x1c9, 0x7, 0xb, 0x2, 0x2, 0x183, 0x1c9, 0x7, 
       0xc, 0x2, 0x2, 0x184, 0x1c9, 0x7, 0xd, 0x2, 0x2, 0x185, 0x1c9, 0x7, 
       0xe, 0x2, 0x2, 0x186, 0x1c9, 0x7, 0xf, 0x2, 0x2, 0x187, 0x1c9, 0x7, 
       0x10, 0x2, 0x2, 0x188, 0x1c9, 0x7, 0x11, 0x2, 0x2, 0x189, 0x1c9, 
       0x7, 0x12, 0x2, 0x2, 0x18a, 0x1c9, 0x7, 0x13, 0x2, 0x2, 0x18b, 0x1c9, 
       0x7, 0x14, 0x2, 0x2, 0x18c, 0x1c9, 0x7, 0x15, 0x2, 0x2, 0x18d, 0x1c9, 
       0x7, 0x16, 0x2, 0x2, 0x18e, 0x1c9, 0x7, 0x17, 0x2, 0x2, 0x18f, 0x1c9, 
       0x7, 0x18, 0x2, 0x2, 0x190, 0x1c9, 0x7, 0x19, 0x2, 0x2, 0x191, 0x1c9, 
       0x7, 0x1a, 0x2, 0x2, 0x192, 0x1c9, 0x7, 0x1c, 0x2, 0x2, 0x193, 0x1c9, 
       0x7, 0x1d, 0x2, 0x2, 0x194, 0x1c9, 0x7, 0x1f, 0x2, 0x2, 0x195, 0x1c9, 
       0x7, 0x20, 0x2, 0x2, 0x196, 0x1c9, 0x7, 0x21, 0x2, 0x2, 0x197, 0x1c9, 
       0x7, 0x23, 0x2, 0x2, 0x198, 0x1c9, 0x7, 0x24, 0x2, 0x2, 0x199, 0x1c9, 
       0x7, 0x25, 0x2, 0x2, 0x19a, 0x1c9, 0x7, 0x27, 0x2, 0x2, 0x19b, 0x1c9, 
       0x7, 0x28, 0x2, 0x2, 0x19c, 0x1c9, 0x7, 0x2a, 0x2, 0x2, 0x19d, 0x1c9, 
       0x7, 0x2b, 0x2, 0x2, 0x19e, 0x1c9, 0x7, 0x2c, 0x2, 0x2, 0x19f, 0x1c9, 
       0x7, 0x2d, 0x2, 0x2, 0x1a0, 0x1c9, 0x7, 0x2e, 0x2, 0x2, 0x1a1, 0x1c9, 
       0x7, 0x2f, 0x2, 0x2, 0x1a2, 0x1c9, 0x7, 0x30, 0x2, 0x2, 0x1a3, 0x1c9, 
       0x7, 0x33, 0x2, 0x2, 0x1a4, 0x1c9, 0x7, 0x34, 0x2, 0x2, 0x1a5, 0x1c9, 
       0x7, 0x35, 0x2, 0x2, 0x1a6, 0x1c9, 0x7, 0x38, 0x2, 0x2, 0x1a7, 0x1c9, 
       0x7, 0x36, 0x2, 0x2, 0x1a8, 0x1c9, 0x7, 0x37, 0x2, 0x2, 0x1a9, 0x1c9, 
       0x7, 0x39, 0x2, 0x2, 0x1aa, 0x1c9, 0x7, 0x3b, 0x2, 0x2, 0x1ab, 0x1c9, 
       0x7, 0x3c, 0x2, 0x2, 0x1ac, 0x1c9, 0x7, 0x3d, 0x2, 0x2, 0x1ad, 0x1c9, 
       0x7, 0x3e, 0x2, 0x2, 0x1ae, 0x1c9, 0x7, 0x3f, 0x2, 0x2, 0x1af, 0x1c9, 
       0x7, 0x40, 0x2, 0x2, 0x1b0, 0x1c9, 0x7, 0x41, 0x2, 0x2, 0x1b1, 0x1c9, 
       0x7, 0x42, 0x2, 0x2, 0x1b2, 0x1c9, 0x7, 0x44, 0x2, 0x2, 0x1b3, 0x1c9, 
       0x7, 0x45, 0x2, 0x2, 0x1b4, 0x1c9, 0x7, 0x46, 0x2, 0x2, 0x1b5, 0x1c9, 
       0x7, 0x47, 0x2, 0x2, 0x1b6, 0x1c9, 0x7, 0x48, 0x2, 0x2, 0x1b7, 0x1c9, 
       0x7, 0x49, 0x2, 0x2, 0x1b8, 0x1c9, 0x7, 0x4b, 0x2, 0x2, 0x1b9, 0x1c9, 
       0x7, 0x4c, 0x2, 0x2, 0x1ba, 0x1c9, 0x7, 0x4d, 0x2, 0x2, 0x1bb, 0x1c9, 
       0x7, 0x4e, 0x2, 0x2, 0x1bc, 0x1c9, 0x7, 0x4f, 0x2, 0x2, 0x1bd, 0x1c9, 
       0x7, 0x50, 0x2, 0x2, 0x1be, 0x1c9, 0x7, 0x51, 0x2, 0x2, 0x1bf, 0x1c9, 
       0x7, 0x52, 0x2, 0x2, 0x1c0, 0x1c9, 0x7, 0x53, 0x2, 0x2, 0x1c1, 0x1c9, 
       0x7, 0x54, 0x2, 0x2, 0x1c2, 0x1c9, 0x7, 0x55, 0x2, 0x2, 0x1c3, 0x1c9, 
       0x7, 0x56, 0x2, 0x2, 0x1c4, 0x1c9, 0x7, 0x57, 0x2, 0x2, 0x1c5, 0x1c9, 
       0x7, 0x58, 0x2, 0x2, 0x1c6, 0x1c9, 0x7, 0x59, 0x2, 0x2, 0x1c7, 0x1c9, 
       0x7, 0x5a, 0x2, 0x2, 0x1c8, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x17b, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x17d, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x17f, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x180, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x181, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x182, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x183, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x184, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x185, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x186, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x187, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x188, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x189, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18b, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18d, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x18f, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x190, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x191, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x192, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x193, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x194, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x195, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x196, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x197, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x198, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19b, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19d, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x19f, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a3, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a5, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a7, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ab, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ad, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1af, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b1, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b5, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1bd, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1bf, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c5, 
       0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x1c9, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1ce, 
       0x7, 0xca, 0x2, 0x2, 0x1cb, 0x1ce, 0x7, 0xcb, 0x2, 0x2, 0x1cc, 0x1ce, 
       0x5, 0x2, 0x2, 0x2, 0x1cd, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1e2, 0x5, 0xb8, 0x5d, 0x2, 0x1d0, 0x1e2, 
       0x5, 0xba, 0x5e, 0x2, 0x1d1, 0x1e2, 0x5, 0xb4, 0x5b, 0x2, 0x1d2, 
       0x1e2, 0x5, 0xb6, 0x5c, 0x2, 0x1d3, 0x1e2, 0x5, 0xb2, 0x5a, 0x2, 
       0x1d4, 0x1e2, 0x5, 0xa6, 0x54, 0x2, 0x1d5, 0x1e2, 0x5, 0x8, 0x5, 
       0x2, 0x1d6, 0x1e2, 0x5, 0x42, 0x22, 0x2, 0x1d7, 0x1e2, 0x5, 0xa, 
       0x6, 0x2, 0x1d8, 0x1e2, 0x5, 0x52, 0x2a, 0x2, 0x1d9, 0x1e2, 0x5, 
       0x54, 0x2b, 0x2, 0x1da, 0x1e2, 0x5, 0xc, 0x7, 0x2, 0x1db, 0x1e2, 
       0x5, 0x68, 0x35, 0x2, 0x1dc, 0x1e2, 0x5, 0x6a, 0x36, 0x2, 0x1dd, 
       0x1e2, 0x5, 0x10, 0x9, 0x2, 0x1de, 0x1e2, 0x5, 0x12, 0xa, 0x2, 0x1df, 
       0x1e2, 0x5, 0x9e, 0x50, 0x2, 0x1e0, 0x1e2, 0x5, 0xa0, 0x51, 0x2, 
       0x1e1, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d2, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d8, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1da, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1dc, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1de, 0x3, 0x2, 0x2, 0x2, 
       0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e0, 0x3, 0x2, 0x2, 0x2, 
       0x1e2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1f3, 0x5, 0x20, 0x11, 0x2, 
       0x1e4, 0x1f3, 0x5, 0x22, 0x12, 0x2, 0x1e5, 0x1f3, 0x5, 0x24, 0x13, 
       0x2, 0x1e6, 0x1f3, 0x5, 0x26, 0x14, 0x2, 0x1e7, 0x1f3, 0x5, 0x28, 
       0x15, 0x2, 0x1e8, 0x1f3, 0x5, 0x2a, 0x16, 0x2, 0x1e9, 0x1f3, 0x5, 
       0x2c, 0x17, 0x2, 0x1ea, 0x1f3, 0x5, 0x2e, 0x18, 0x2, 0x1eb, 0x1f3, 
       0x5, 0x30, 0x19, 0x2, 0x1ec, 0x1f3, 0x5, 0x32, 0x1a, 0x2, 0x1ed, 
       0x1f3, 0x5, 0x34, 0x1b, 0x2, 0x1ee, 0x1f3, 0x5, 0x36, 0x1c, 0x2, 
       0x1ef, 0x1f3, 0x5, 0x3c, 0x1f, 0x2, 0x1f0, 0x1f3, 0x5, 0x3e, 0x20, 
       0x2, 0x1f1, 0x1f3, 0x5, 0x40, 0x21, 0x2, 0x1f2, 0x1e3, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1e5, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1e7, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1e9, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1eb, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ed, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ef, 0x3, 0x2, 
       0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 
       0x2, 0x2, 0x1f3, 0x9, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1fa, 0x5, 0x44, 
       0x23, 0x2, 0x1f5, 0x1fa, 0x5, 0x46, 0x24, 0x2, 0x1f6, 0x1fa, 0x5, 
       0x4c, 0x27, 0x2, 0x1f7, 0x1fa, 0x5, 0x4e, 0x28, 0x2, 0x1f8, 0x1fa, 
       0x5, 0x50, 0x29, 0x2, 0x1f9, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f5, 
       0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f7, 
       0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1ff, 0x5, 0x5e, 0x30, 0x2, 0x1fc, 0x1ff, 
       0x5, 0x60, 0x31, 0x2, 0x1fd, 0x1ff, 0x5, 0x62, 0x32, 0x2, 0x1fe, 
       0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fe, 
       0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0xd, 0x3, 0x2, 0x2, 0x2, 0x200, 
       0x20c, 0x5, 0xc0, 0x61, 0x2, 0x201, 0x20c, 0x5, 0xc6, 0x64, 0x2, 
       0x202, 0x20c, 0x5, 0xc8, 0x65, 0x2, 0x203, 0x20c, 0x5, 0xcc, 0x67, 
       0x2, 0x204, 0x20c, 0x5, 0xce, 0x68, 0x2, 0x205, 0x20c, 0x5, 0xd2, 
       0x6a, 0x2, 0x206, 0x20c, 0x5, 0xd4, 0x6b, 0x2, 0x207, 0x20c, 0x5, 
       0xd8, 0x6d, 0x2, 0x208, 0x20c, 0x5, 0xda, 0x6e, 0x2, 0x209, 0x20c, 
       0x5, 0xdc, 0x6f, 0x2, 0x20a, 0x20c, 0x5, 0x14, 0xb, 0x2, 0x20b, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x201, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x202, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x203, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x204, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x205, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x206, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x208, 
       0x3, 0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20a, 
       0x3, 0x2, 0x2, 0x2, 0x20c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x216, 
       0x5, 0x92, 0x4a, 0x2, 0x20e, 0x216, 0x5, 0x78, 0x3d, 0x2, 0x20f, 
       0x216, 0x5, 0x86, 0x44, 0x2, 0x210, 0x216, 0x5, 0x88, 0x45, 0x2, 
       0x211, 0x216, 0x5, 0x8a, 0x46, 0x2, 0x212, 0x216, 0x5, 0x8c, 0x47, 
       0x2, 0x213, 0x216, 0x5, 0x8e, 0x48, 0x2, 0x214, 0x216, 0x5, 0x90, 
       0x49, 0x2, 0x215, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x215, 0x20e, 0x3, 0x2, 
       0x2, 0x2, 0x215, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x215, 0x210, 0x3, 0x2, 
       0x2, 0x2, 0x215, 0x211, 0x3, 0x2, 0x2, 0x2, 0x215, 0x212, 0x3, 0x2, 
       0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 0x215, 0x214, 0x3, 0x2, 
       0x2, 0x2, 0x216, 0x11, 0x3, 0x2, 0x2, 0x2, 0x217, 0x21b, 0x5, 0x98, 
       0x4d, 0x2, 0x218, 0x21b, 0x5, 0x9a, 0x4e, 0x2, 0x219, 0x21b, 0x5, 
       0x9c, 0x4f, 0x2, 0x21a, 0x217, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x218, 
       0x3, 0x2, 0x2, 0x2, 0x21a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 0x7, 0x2d, 0x2, 0x2, 0x21d, 0x21e, 
       0x7, 0x16, 0x2, 0x2, 0x21e, 0x21f, 0x7, 0x23, 0x2, 0x2, 0x21f, 0x220, 
       0x5, 0x16, 0xc, 0x2, 0x220, 0x221, 0x9, 0x2, 0x2, 0x2, 0x221, 0x224, 
       0x7, 0x27, 0x2, 0x2, 0x222, 0x223, 0x7, 0x29, 0x2, 0x2, 0x223, 0x225, 
       0x7, 0x8, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 
       0x3, 0x2, 0x2, 0x2, 0x225, 0x228, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 
       0x7, 0x18, 0x2, 0x2, 0x227, 0x229, 0x5, 0x18, 0xd, 0x2, 0x228, 0x226, 
       0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22c, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x42, 0x2, 0x2, 0x22b, 0x22d, 
       0x5, 0x1a, 0xe, 0x2, 0x22c, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 
       0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 
       0x7, 0x7f, 0x2, 0x2, 0x22f, 0x230, 0x5, 0x1c, 0xf, 0x2, 0x230, 0x15, 
       0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x5, 0x142, 0xa2, 0x2, 0x232, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x5, 0x142, 0xa2, 0x2, 0x234, 0x19, 
       0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0x5, 0x142, 0xa2, 0x2, 0x236, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x5, 0x164, 0xb3, 0x2, 0x238, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x5, 0x4, 0x3, 0x2, 0x23a, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x7, 0x8b, 0x2, 0x2, 0x23c, 0x23d, 
       0x7, 0x40, 0x2, 0x2, 0x23d, 0x23e, 0x5, 0x1e, 0x10, 0x2, 0x23e, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x1c, 0x2, 0x2, 0x240, 0x241, 
       0x7, 0x40, 0x2, 0x2, 0x241, 0x242, 0x5, 0x1e, 0x10, 0x2, 0x242, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x7, 0xb4, 0x2, 0x2, 0x244, 0x245, 
       0x7, 0x41, 0x2, 0x2, 0x245, 0x25, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 
       0x7, 0x8b, 0x2, 0x2, 0x247, 0x248, 0x7, 0x58, 0x2, 0x2, 0x248, 0x24c, 
       0x5, 0x1e, 0x10, 0x2, 0x249, 0x24a, 0x7, 0x28, 0x2, 0x2, 0x24a, 0x24b, 
       0x7, 0x84, 0x2, 0x2, 0x24b, 0x24d, 0x5, 0x142, 0xa2, 0x2, 0x24c, 
       0x249, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x7, 0xb3, 0x2, 0x2, 0x24f, 
       0x250, 0x7, 0x35, 0x2, 0x2, 0x250, 0x251, 0x7, 0x20, 0x2, 0x2, 0x251, 
       0x252, 0x5, 0x1e, 0x10, 0x2, 0x252, 0x253, 0x7, 0x4f, 0x2, 0x2, 0x253, 
       0x254, 0x5, 0x142, 0xa2, 0x2, 0x254, 0x29, 0x3, 0x2, 0x2, 0x2, 0x255, 
       0x256, 0x7, 0x1c, 0x2, 0x2, 0x256, 0x257, 0x7, 0x58, 0x2, 0x2, 0x257, 
       0x258, 0x5, 0x1e, 0x10, 0x2, 0x258, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x259, 
       0x25a, 0x7, 0xb4, 0x2, 0x2, 0x25a, 0x25b, 0x7, 0x59, 0x2, 0x2, 0x25b, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 0xb3, 0x2, 0x2, 0x25d, 
       0x25e, 0x7, 0x40, 0x2, 0x2, 0x25e, 0x25f, 0x7, 0x20, 0x2, 0x2, 0x25f, 
       0x260, 0x5, 0x1e, 0x10, 0x2, 0x260, 0x261, 0x7, 0x4f, 0x2, 0x2, 0x261, 
       0x262, 0x5, 0x1e, 0x10, 0x2, 0x262, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x263, 
       0x264, 0x7, 0xf, 0x2, 0x2, 0x264, 0x265, 0x7, 0x40, 0x2, 0x2, 0x265, 
       0x266, 0x7, 0x20, 0x2, 0x2, 0x266, 0x267, 0x5, 0x1e, 0x10, 0x2, 0x267, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26c, 0x7, 0x25, 0x2, 0x2, 0x269, 
       0x26a, 0x7, 0x7c, 0x2, 0x2, 0x26a, 0x26d, 0x7, 0x37, 0x2, 0x2, 0x26b, 
       0x26d, 0x5, 0x3a, 0x1e, 0x2, 0x26c, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26c, 
       0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 
       0x26f, 0x7, 0x4f, 0x2, 0x2, 0x26f, 0x270, 0x5, 0x1e, 0x10, 0x2, 0x270, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x271, 0x275, 0x7, 0x1a, 0x2, 0x2, 0x272, 
       0x273, 0x7, 0x7c, 0x2, 0x2, 0x273, 0x276, 0x7, 0x37, 0x2, 0x2, 0x274, 
       0x276, 0x5, 0x3a, 0x1e, 0x2, 0x275, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 
       0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 
       0x278, 0x7, 0x4f, 0x2, 0x2, 0x278, 0x279, 0x5, 0x1e, 0x10, 0x2, 0x279, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27e, 0x7, 0x3f, 0x2, 0x2, 0x27b, 
       0x27c, 0x7, 0x7c, 0x2, 0x2, 0x27c, 0x27f, 0x7, 0x37, 0x2, 0x2, 0x27d, 
       0x27f, 0x5, 0x3a, 0x1e, 0x2, 0x27e, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27e, 
       0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x281, 0x7, 0x23, 0x2, 0x2, 0x281, 0x282, 0x5, 0x1e, 0x10, 0x2, 0x282, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x9, 0x3, 0x2, 0x2, 0x284, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x285, 0x28a, 0x5, 0x38, 0x1d, 0x2, 0x286, 
       0x287, 0x7, 0x63, 0x2, 0x2, 0x287, 0x289, 0x5, 0x38, 0x1d, 0x2, 0x288, 
       0x286, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28a, 
       0x288, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28d, 
       0x28e, 0x7, 0xb4, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x37, 0x2, 0x2, 0x28f, 
       0x290, 0x7, 0x20, 0x2, 0x2, 0x290, 0x291, 0x5, 0x1e, 0x10, 0x2, 0x291, 
       0x3d, 0x3, 0x2, 0x2, 0x2, 0x292, 0x293, 0x7, 0xb4, 0x2, 0x2, 0x293, 
       0x294, 0x7, 0x40, 0x2, 0x2, 0x294, 0x295, 0x7, 0x20, 0x2, 0x2, 0x295, 
       0x296, 0x5, 0x1e, 0x10, 0x2, 0x296, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x297, 
       0x298, 0x7, 0xb4, 0x2, 0x2, 0x298, 0x299, 0x7, 0x59, 0x2, 0x2, 0x299, 
       0x29a, 0x7, 0x20, 0x2, 0x2, 0x29a, 0x29b, 0x5, 0x1e, 0x10, 0x2, 0x29b, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x1d, 0x2, 0x2, 0x29d, 
       0x29e, 0x7, 0x19, 0x2, 0x2, 0x29e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x29f, 
       0x2a0, 0x7, 0xb3, 0x2, 0x2, 0x2a0, 0x2a1, 0x7, 0x3e, 0x2, 0x2, 0x2a1, 
       0x2a2, 0x7, 0x40, 0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x4f, 0x2, 0x2, 0x2a3, 
       0x2a7, 0x9, 0x4, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0xc1, 0x2, 0x2, 0x2a5, 
       0x2a6, 0x7, 0x36, 0x2, 0x2, 0x2a6, 0x2a8, 0x5, 0x142, 0xa2, 0x2, 
       0x2a7, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 
       0x2a8, 0x45, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x7, 0xb4, 0x2, 0x2, 
       0x2aa, 0x2ab, 0x7, 0x3e, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 0x40, 0x2, 
       0x2, 0x2ac, 0x47, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0x5, 0x4, 0x3, 
       0x2, 0x2ae, 0x49, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x5, 0x142, 0xa2, 
       0x2, 0x2b0, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x3b, 0x2, 
       0x2, 0x2b2, 0x2b3, 0x7, 0x3c, 0x2, 0x2, 0x2b3, 0x2b4, 0x5, 0x48, 
       0x25, 0x2, 0x2b4, 0x2b8, 0x9, 0x5, 0x2, 0x2, 0x2b5, 0x2b6, 0x7, 0xc1, 
       0x2, 0x2, 0x2b6, 0x2b7, 0x7, 0x4e, 0x2, 0x2, 0x2b7, 0x2b9, 0x5, 0x142, 
       0xa2, 0x2, 0x2b8, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 0x2, 
       0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x7, 0x4f, 
       0x2, 0x2, 0x2bb, 0x2bc, 0x5, 0x4a, 0x26, 0x2, 0x2bc, 0x4d, 0x3, 0x2, 
       0x2, 0x2, 0x2bd, 0x2be, 0x7, 0x1c, 0x2, 0x2, 0x2be, 0x2bf, 0x7, 0x3c, 
       0x2, 0x2, 0x2bf, 0x2c0, 0x5, 0x48, 0x25, 0x2, 0x2c0, 0x4f, 0x3, 0x2, 
       0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0xb4, 0x2, 0x2, 0x2c2, 0x2c3, 0x7, 0x3d, 
       0x2, 0x2, 0x2c3, 0x51, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x9, 0x6, 
       0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x17, 0x2, 0x2, 0x2c6, 0x2c7, 0x7, 0x1b, 
       0x2, 0x2, 0x2c7, 0x53, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x7, 0x21, 
       0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0xa4, 0x2, 0x2, 0x2ca, 0x55, 0x3, 0x2, 
       0x2, 0x2, 0x2cb, 0x2cc, 0x5, 0x4, 0x3, 0x2, 0x2cc, 0x57, 0x3, 0x2, 
       0x2, 0x2, 0x2cd, 0x2cf, 0xb, 0x2, 0x2, 0x2, 0x2ce, 0x2cd, 0x3, 0x2, 
       0x2, 0x2, 0x2cf, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x3, 0x2, 
       0x2, 0x2, 0x2d0, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x59, 0x3, 0x2, 
       0x2, 0x2, 0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x5d, 
       0x2, 0x2, 0x2d4, 0x2d5, 0x7, 0x5e, 0x2, 0x2, 0x2d5, 0x5b, 0x3, 0x2, 
       0x2, 0x2, 0x2d6, 0x2d7, 0x5, 0x10c, 0x87, 0x2, 0x2d7, 0x2d8, 0x5, 
       0x10c, 0x87, 0x2, 0x2d8, 0x2d9, 0x5, 0x10a, 0x86, 0x2, 0x2d9, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x7, 0x8b, 0x2, 0x2, 0x2db, 0x2dc, 
       0x7, 0x53, 0x2, 0x2, 0x2dc, 0x2e3, 0x5, 0x56, 0x2c, 0x2, 0x2dd, 0x2e0, 
       0x7, 0xa9, 0x2, 0x2, 0x2de, 0x2e1, 0x5, 0x5a, 0x2e, 0x2, 0x2df, 0x2e1, 
       0x5, 0x5c, 0x2f, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 
       0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e4, 0x9, 0x7, 0x2, 0x2, 0x2e3, 0x2dd, 
       0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 
       0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x9, 0x8, 0x2, 0x2, 0x2e6, 0x2e7, 
       0x7, 0x10, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0x1f, 0x2, 0x2, 0x2e8, 0x2e9, 
       0x5, 0x58, 0x2d, 0x2, 0x2e9, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 
       0x7, 0x1c, 0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0x53, 0x2, 0x2, 0x2ec, 0x2ed, 
       0x5, 0x56, 0x2c, 0x2, 0x2ed, 0x61, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 
       0x7, 0xb4, 0x2, 0x2, 0x2ef, 0x2f0, 0x7, 0x54, 0x2, 0x2, 0x2f0, 0x63, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x47, 0x2, 0x2, 0x2f2, 0x2f8, 
       0x7, 0x2a, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 0x39, 0x2, 0x2, 0x2f4, 0x2f8, 
       0x7, 0x11, 0x2, 0x2, 0x2f5, 0x2f6, 0x7, 0x39, 0x2, 0x2, 0x2f6, 0x2f8, 
       0x7, 0x55, 0x2, 0x2, 0x2f7, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f3, 
       0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x9, 0x9, 0x2, 0x2, 0x2fa, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x7, 0xb3, 0x2, 0x2, 0x2fc, 0x2fd, 
       0x5, 0x66, 0x34, 0x2, 0x2fd, 0x2fe, 0x7, 0x51, 0x2, 0x2, 0x2fe, 0x2ff, 
       0x7, 0x2a, 0x2, 0x2, 0x2ff, 0x300, 0x7, 0x2c, 0x2, 0x2, 0x300, 0x301, 
       0x5, 0x64, 0x33, 0x2, 0x301, 0x69, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 
       0x7, 0x8b, 0x2, 0x2, 0x303, 0x304, 0x7, 0x47, 0x2, 0x2, 0x304, 0x6b, 
       0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x5, 0x4, 0x3, 0x2, 0x306, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x307, 0x30c, 0x5, 0x4, 0x3, 0x2, 0x308, 0x309, 
       0x7, 0x73, 0x2, 0x2, 0x309, 0x30b, 0x5, 0x4, 0x3, 0x2, 0x30a, 0x308, 
       0x3, 0x2, 0x2, 0x2, 0x30b, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30a, 
       0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x314, 
       0x5, 0x6e, 0x38, 0x2, 0x310, 0x311, 0x7, 0x64, 0x2, 0x2, 0x311, 0x313, 
       0x5, 0x6e, 0x38, 0x2, 0x312, 0x310, 0x3, 0x2, 0x2, 0x2, 0x313, 0x316, 
       0x3, 0x2, 0x2, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 
       0x3, 0x2, 0x2, 0x2, 0x315, 0x71, 0x3, 0x2, 0x2, 0x2, 0x316, 0x314, 
       0x3, 0x2, 0x2, 0x2, 0x317, 0x31c, 0x5, 0x70, 0x39, 0x2, 0x318, 0x319, 
       0x7, 0x63, 0x2, 0x2, 0x319, 0x31b, 0x5, 0x70, 0x39, 0x2, 0x31a, 0x318, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x31e, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x322, 
       0x5, 0x72, 0x3a, 0x2, 0x320, 0x322, 0x5, 0x142, 0xa2, 0x2, 0x321, 
       0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 0x320, 0x3, 0x2, 0x2, 0x2, 0x322, 
       0x75, 0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x7, 0x52, 0x2, 0x2, 0x324, 
       0x32a, 0x5, 0xde, 0x70, 0x2, 0x325, 0x326, 0x7, 0x9, 0x2, 0x2, 0x326, 
       0x32a, 0x5, 0x142, 0xa2, 0x2, 0x327, 0x328, 0x7, 0xb, 0x2, 0x2, 0x328, 
       0x32a, 0x5, 0x142, 0xa2, 0x2, 0x329, 0x323, 0x3, 0x2, 0x2, 0x2, 0x329, 
       0x325, 0x3, 0x2, 0x2, 0x2, 0x329, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32a, 
       0x77, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32e, 0x5, 0x80, 0x41, 0x2, 0x32c, 
       0x32e, 0x5, 0x84, 0x43, 0x2, 0x32d, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32d, 
       0x32c, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x79, 0x3, 0x2, 0x2, 0x2, 0x32f, 
       0x330, 0x5, 0x142, 0xa2, 0x2, 0x330, 0x331, 0x7, 0x66, 0x2, 0x2, 
       0x331, 0x332, 0x5, 0x142, 0xa2, 0x2, 0x332, 0x7b, 0x3, 0x2, 0x2, 
       0x2, 0x333, 0x33c, 0x7, 0x61, 0x2, 0x2, 0x334, 0x339, 0x5, 0x7a, 
       0x3e, 0x2, 0x335, 0x336, 0x7, 0x63, 0x2, 0x2, 0x336, 0x338, 0x5, 
       0x7a, 0x3e, 0x2, 0x337, 0x335, 0x3, 0x2, 0x2, 0x2, 0x338, 0x33b, 
       0x3, 0x2, 0x2, 0x2, 0x339, 0x337, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 
       0x3, 0x2, 0x2, 0x2, 0x33a, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x339, 
       0x3, 0x2, 0x2, 0x2, 0x33c, 0x334, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 
       0x3, 0x2, 0x2, 0x2, 0x33d, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 
       0x7, 0x62, 0x2, 0x2, 0x33f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 
       0x7, 0x50, 0x2, 0x2, 0x341, 0x34c, 0x5, 0x74, 0x3b, 0x2, 0x342, 0x343, 
       0x7, 0x14, 0x2, 0x2, 0x343, 0x34c, 0x5, 0x70, 0x39, 0x2, 0x344, 0x345, 
       0x7, 0xd, 0x2, 0x2, 0x345, 0x34c, 0x5, 0x142, 0xa2, 0x2, 0x346, 0x347, 
       0x7, 0x13, 0x2, 0x2, 0x347, 0x34c, 0x5, 0x7c, 0x3f, 0x2, 0x348, 0x349, 
       0x7, 0x15, 0x2, 0x2, 0x349, 0x34c, 0x5, 0x7c, 0x3f, 0x2, 0x34a, 0x34c, 
       0x5, 0x76, 0x3c, 0x2, 0x34b, 0x340, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x342, 
       0x3, 0x2, 0x2, 0x2, 0x34b, 0x344, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x346, 
       0x3, 0x2, 0x2, 0x2, 0x34b, 0x348, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34a, 
       0x3, 0x2, 0x2, 0x2, 0x34c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 
       0x7, 0x8b, 0x2, 0x2, 0x34e, 0x34f, 0x7, 0x2b, 0x2, 0x2, 0x34f, 0x350, 
       0x7, 0x4b, 0x2, 0x2, 0x350, 0x354, 0x5, 0x6c, 0x37, 0x2, 0x351, 0x353, 
       0x5, 0x7e, 0x40, 0x2, 0x352, 0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x354, 0x352, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 
       0x3, 0x2, 0x2, 0x2, 0x355, 0x81, 0x3, 0x2, 0x2, 0x2, 0x356, 0x354, 
       0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x7, 0x50, 0x2, 0x2, 0x358, 0x35d, 
       0x5, 0x74, 0x3b, 0x2, 0x359, 0x35a, 0x7, 0x43, 0x2, 0x2, 0x35a, 0x35d, 
       0x5, 0x142, 0xa2, 0x2, 0x35b, 0x35d, 0x5, 0x76, 0x3c, 0x2, 0x35c, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35c, 
       0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x83, 0x3, 0x2, 0x2, 0x2, 0x35e, 
       0x35f, 0x7, 0x8b, 0x2, 0x2, 0x35f, 0x360, 0x7, 0x38, 0x2, 0x2, 0x360, 
       0x361, 0x7, 0x4b, 0x2, 0x2, 0x361, 0x365, 0x5, 0x6c, 0x37, 0x2, 0x362, 
       0x364, 0x5, 0x82, 0x42, 0x2, 0x363, 0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 
       0x367, 0x3, 0x2, 0x2, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 0x2, 0x365, 
       0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x85, 0x3, 0x2, 0x2, 0x2, 0x367, 
       0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 0x7, 0x1c, 0x2, 0x2, 0x369, 
       0x36a, 0x7, 0x4b, 0x2, 0x2, 0x36a, 0x36b, 0x5, 0x6c, 0x37, 0x2, 0x36b, 
       0x87, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36d, 0x7, 0x48, 0x2, 0x2, 0x36d, 
       0x36e, 0x7, 0x4b, 0x2, 0x2, 0x36e, 0x36f, 0x5, 0x6c, 0x37, 0x2, 0x36f, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x7, 0x48, 0x2, 0x2, 0x371, 
       0x372, 0x7, 0x7c, 0x2, 0x2, 0x372, 0x373, 0x7, 0x4c, 0x2, 0x2, 0x373, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x374, 0x375, 0x7, 0x4a, 0x2, 0x2, 0x375, 
       0x376, 0x7, 0x4b, 0x2, 0x2, 0x376, 0x377, 0x5, 0x6c, 0x37, 0x2, 0x377, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x378, 0x379, 0x7, 0x4a, 0x2, 0x2, 0x379, 
       0x37a, 0x7, 0x7c, 0x2, 0x2, 0x37a, 0x37b, 0x7, 0x4c, 0x2, 0x2, 0x37b, 
       0x8f, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x7, 0xb4, 0x2, 0x2, 0x37d, 
       0x37e, 0x7, 0x4c, 0x2, 0x2, 0x37e, 0x91, 0x3, 0x2, 0x2, 0x2, 0x37f, 
       0x380, 0x7, 0xe, 0x2, 0x2, 0x380, 0x381, 0x7, 0x4b, 0x2, 0x2, 0x381, 
       0x384, 0x5, 0x6c, 0x37, 0x2, 0x382, 0x383, 0x7, 0xa, 0x2, 0x2, 0x383, 
       0x385, 0x5, 0x142, 0xa2, 0x2, 0x384, 0x382, 0x3, 0x2, 0x2, 0x2, 0x384, 
       0x385, 0x3, 0x2, 0x2, 0x2, 0x385, 0x388, 0x3, 0x2, 0x2, 0x2, 0x386, 
       0x387, 0x7, 0x4e, 0x2, 0x2, 0x387, 0x389, 0x5, 0x142, 0xa2, 0x2, 
       0x388, 0x386, 0x3, 0x2, 0x2, 0x2, 0x388, 0x389, 0x3, 0x2, 0x2, 0x2, 
       0x389, 0x93, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x5, 0x142, 0xa2, 
       0x2, 0x38b, 0x95, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38d, 0x5, 0x142, 0xa2, 
       0x2, 0x38d, 0x97, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 0x7, 0xb3, 0x2, 
       0x2, 0x38f, 0x390, 0x7, 0x19, 0x2, 0x2, 0x390, 0x391, 0x7, 0x45, 
       0x2, 0x2, 0x391, 0x392, 0x5, 0x94, 0x4b, 0x2, 0x392, 0x393, 0x7, 
       0x4f, 0x2, 0x2, 0x393, 0x394, 0x5, 0x96, 0x4c, 0x2, 0x394, 0x99, 
       0x3, 0x2, 0x2, 0x2, 0x395, 0x396, 0x7, 0xb4, 0x2, 0x2, 0x396, 0x397, 
       0x7, 0x19, 0x2, 0x2, 0x397, 0x398, 0x7, 0x45, 0x2, 0x2, 0x398, 0x399, 
       0x5, 0x94, 0x4b, 0x2, 0x399, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 
       0x7, 0xb4, 0x2, 0x2, 0x39b, 0x39c, 0x7, 0x19, 0x2, 0x2, 0x39c, 0x39d, 
       0x7, 0x46, 0x2, 0x2, 0x39d, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 
       0x7, 0xb4, 0x2, 0x2, 0x39f, 0x3a0, 0x7, 0x5a, 0x2, 0x2, 0x3a0, 0x9f, 
       0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x7, 0x47, 0x2, 0x2, 0x3a2, 0xa1, 
       0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a5, 0x5, 0xa4, 0x53, 0x2, 0x3a4, 0x3a6, 
       0x7, 0x67, 0x2, 0x2, 0x3a5, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 
       0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 
       0x7, 0x2, 0x2, 0x3, 0x3a8, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 
       0x5, 0x6, 0x4, 0x2, 0x3aa, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ac, 
       0x9, 0xa, 0x2, 0x2, 0x3ac, 0x3ad, 0x7, 0x88, 0x2, 0x2, 0x3ad, 0x3ae, 
       0x7, 0xa9, 0x2, 0x2, 0x3ae, 0x3af, 0x5, 0xa8, 0x55, 0x2, 0x3af, 0xa7, 
       0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b1, 0x7, 0x5d, 0x2, 0x2, 0x3b1, 0x3b2, 
       0x5, 0x164, 0xb3, 0x2, 0x3b2, 0x3b3, 0x7, 0x66, 0x2, 0x2, 0x3b3, 
       0x3b4, 0x5, 0x11c, 0x8f, 0x2, 0x3b4, 0x3b5, 0x7, 0x5e, 0x2, 0x2, 
       0x3b5, 0x3b6, 0x7, 0x82, 0x2, 0x2, 0x3b6, 0x3b7, 0x7, 0x95, 0x2, 
       0x2, 0x3b7, 0x3b8, 0x7, 0x5d, 0x2, 0x2, 0x3b8, 0x3b9, 0x5, 0xaa, 
       0x56, 0x2, 0x3b9, 0x3ba, 0x7, 0x5e, 0x2, 0x2, 0x3ba, 0x3d3, 0x3, 
       0x2, 0x2, 0x2, 0x3bb, 0x3bc, 0x7, 0x5d, 0x2, 0x2, 0x3bc, 0x3bd, 0x5, 
       0x164, 0xb3, 0x2, 0x3bd, 0x3be, 0x7, 0x66, 0x2, 0x2, 0x3be, 0x3bf, 
       0x5, 0x11c, 0x8f, 0x2, 0x3bf, 0x3c0, 0x7, 0x5e, 0x2, 0x2, 0x3c0, 
       0x3c1, 0x7, 0x82, 0x2, 0x2, 0x3c1, 0x3c2, 0x5, 0xaa, 0x56, 0x2, 0x3c2, 
       0x3c3, 0x7, 0x9d, 0x2, 0x2, 0x3c3, 0x3c4, 0x7, 0xbc, 0x2, 0x2, 0x3c4, 
       0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x7, 0x5d, 0x2, 0x2, 0x3c6, 
       0x3c7, 0x5, 0x164, 0xb3, 0x2, 0x3c7, 0x3c8, 0x7, 0x66, 0x2, 0x2, 
       0x3c8, 0x3c9, 0x5, 0x11c, 0x8f, 0x2, 0x3c9, 0x3ca, 0x7, 0x5e, 0x2, 
       0x2, 0x3ca, 0x3cb, 0x7, 0x82, 0x2, 0x2, 0x3cb, 0x3cc, 0x7, 0x5d, 
       0x2, 0x2, 0x3cc, 0x3cd, 0x5, 0xaa, 0x56, 0x2, 0x3cd, 0x3ce, 0x7, 
       0x5e, 0x2, 0x2, 0x3ce, 0x3cf, 0x7, 0x9d, 0x2, 0x2, 0x3cf, 0x3d0, 
       0x7, 0xa6, 0x2, 0x2, 0x3d0, 0x3d1, 0x7, 0x9f, 0x2, 0x2, 0x3d1, 0x3d3, 
       0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3bb, 
       0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d5, 0x5, 0x164, 0xb3, 0x2, 0x3d5, 0x3dc, 
       0x5, 0x15e, 0xb0, 0x2, 0x3d6, 0x3d7, 0x7, 0x63, 0x2, 0x2, 0x3d7, 
       0x3d8, 0x5, 0x164, 0xb3, 0x2, 0x3d8, 0x3d9, 0x5, 0x15e, 0xb0, 0x2, 
       0x3d9, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3d6, 0x3, 0x2, 0x2, 0x2, 
       0x3db, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3da, 0x3, 0x2, 0x2, 0x2, 
       0x3dc, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0xab, 0x3, 0x2, 0x2, 0x2, 
       0x3de, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x7, 0xb7, 0x2, 0x2, 
       0x3e0, 0x3e1, 0x7, 0x9c, 0x2, 0x2, 0x3e1, 0xad, 0x3, 0x2, 0x2, 0x2, 
       0x3e2, 0x3e3, 0x7, 0x9b, 0x2, 0x2, 0x3e3, 0x3e4, 0x7, 0x9c, 0x2, 
       0x2, 0x3e4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0x7, 0x88, 0x2, 
       0x2, 0x3e6, 0x3e7, 0x7, 0x9c, 0x2, 0x2, 0x3e7, 0xb1, 0x3, 0x2, 0x2, 
       0x2, 0x3e8, 0x3ec, 0x7, 0xb4, 0x2, 0x2, 0x3e9, 0x3ed, 0x5, 0xac, 
       0x57, 0x2, 0x3ea, 0x3ed, 0x5, 0xae, 0x58, 0x2, 0x3eb, 0x3ed, 0x5, 
       0xb0, 0x59, 0x2, 0x3ec, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ea, 
       0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ef, 0x7, 0x96, 0x2, 0x2, 0x3ef, 0x3f0, 
       0x5, 0xb8, 0x5d, 0x2, 0x3f0, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 
       0x7, 0xae, 0x2, 0x2, 0x3f2, 0x3f3, 0x5, 0xb8, 0x5d, 0x2, 0x3f3, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f8, 0x5, 0xbc, 0x5f, 0x2, 0x3f5, 0x3f7, 
       0x5, 0xbe, 0x60, 0x2, 0x3f6, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3fa, 
       0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3f9, 
       0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3f8, 
       0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fd, 0x5, 0xe4, 0x73, 0x2, 0x3fc, 0x3fb, 
       0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x3fe, 0x401, 0x5, 0x172, 0xba, 0x2, 0x3ff, 0x401, 
       0x5, 0x174, 0xbb, 0x2, 0x400, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x400, 0x3ff, 
       0x3, 0x2, 0x2, 0x2, 0x401, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x402, 0x406, 
       0x5, 0xe, 0x8, 0x2, 0x403, 0x405, 0x5, 0xe, 0x8, 0x2, 0x404, 0x403, 
       0x3, 0x2, 0x2, 0x2, 0x405, 0x408, 0x3, 0x2, 0x2, 0x2, 0x406, 0x404, 
       0x3, 0x2, 0x2, 0x2, 0x406, 0x407, 0x3, 0x2, 0x2, 0x2, 0x407, 0xbd, 
       0x3, 0x2, 0x2, 0x2, 0x408, 0x406, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 
       0x7, 0xbb, 0x2, 0x2, 0x40a, 0x40b, 0x7, 0x7c, 0x2, 0x2, 0x40b, 0x40f, 
       0x5, 0xbc, 0x5f, 0x2, 0x40c, 0x40d, 0x7, 0xbb, 0x2, 0x2, 0x40d, 0x40f, 
       0x5, 0xbc, 0x5f, 0x2, 0x40e, 0x409, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x40c, 
       0x3, 0x2, 0x2, 0x2, 0x40f, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x410, 0x412, 
       0x7, 0xaa, 0x2, 0x2, 0x411, 0x410, 0x3, 0x2, 0x2, 0x2, 0x411, 0x412, 
       0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 
       0x7, 0xa2, 0x2, 0x2, 0x414, 0x416, 0x5, 0xfa, 0x7e, 0x2, 0x415, 0x417, 
       0x5, 0xf8, 0x7d, 0x2, 0x416, 0x415, 0x3, 0x2, 0x2, 0x2, 0x416, 0x417, 
       0x3, 0x2, 0x2, 0x2, 0x417, 0x419, 0x3, 0x2, 0x2, 0x2, 0x418, 0x41a, 
       0x5, 0xc2, 0x62, 0x2, 0x419, 0x418, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 
       0x3, 0x2, 0x2, 0x2, 0x41a, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41d, 
       0x5, 0xc4, 0x63, 0x2, 0x41c, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 
       0x3, 0x2, 0x2, 0x2, 0x41d, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 
       0x7, 0xba, 0x2, 0x2, 0x41f, 0x420, 0x7, 0x7f, 0x2, 0x2, 0x420, 0x428, 
       0x5, 0x142, 0xa2, 0x2, 0x421, 0x422, 0x7, 0xba, 0x2, 0x2, 0x422, 
       0x423, 0x7, 0x23, 0x2, 0x2, 0x423, 0x424, 0x5, 0x142, 0xa2, 0x2, 
       0x424, 0x425, 0x7, 0x4f, 0x2, 0x2, 0x425, 0x426, 0x5, 0x142, 0xa2, 
       0x2, 0x426, 0x428, 0x3, 0x2, 0x2, 0x2, 0x427, 0x41e, 0x3, 0x2, 0x2, 
       0x2, 0x427, 0x421, 0x3, 0x2, 0x2, 0x2, 0x428, 0xc3, 0x3, 0x2, 0x2, 
       0x2, 0x429, 0x42a, 0x7, 0xce, 0x2, 0x2, 0x42a, 0x42b, 0x7, 0x7f, 
       0x2, 0x2, 0x42b, 0x433, 0x5, 0x142, 0xa2, 0x2, 0x42c, 0x42d, 0x7, 
       0xce, 0x2, 0x2, 0x42d, 0x42e, 0x7, 0xcf, 0x2, 0x2, 0x42e, 0x42f, 
       0x5, 0x142, 0xa2, 0x2, 0x42f, 0x430, 0x7, 0x4f, 0x2, 0x2, 0x430, 
       0x431, 0x5, 0x142, 0xa2, 0x2, 0x431, 0x433, 0x3, 0x2, 0x2, 0x2, 0x432, 
       0x429, 0x3, 0x2, 0x2, 0x2, 0x432, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x433, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0x434, 0x435, 0x7, 0xbe, 0x2, 0x2, 0x435, 
       0x436, 0x5, 0x120, 0x91, 0x2, 0x436, 0x437, 0x7, 0x7f, 0x2, 0x2, 
       0x437, 0x438, 0x5, 0x164, 0xb3, 0x2, 0x438, 0xc7, 0x3, 0x2, 0x2, 
       0x2, 0x439, 0x43a, 0x7, 0xa5, 0x2, 0x2, 0x43a, 0x43e, 0x5, 0xfc, 
       0x7f, 0x2, 0x43b, 0x43d, 0x5, 0xca, 0x66, 0x2, 0x43c, 0x43b, 0x3, 
       0x2, 0x2, 0x2, 0x43d, 0x440, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x43c, 0x3, 
       0x2, 0x2, 0x2, 0x43e, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x43f, 0xc9, 0x3, 
       0x2, 0x2, 0x2, 0x440, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x441, 0x442, 0x7, 
       0xa9, 0x2, 0x2, 0x442, 0x443, 0x7, 0xa2, 0x2, 0x2, 0x443, 0x448, 
       0x5, 0xce, 0x68, 0x2, 0x444, 0x445, 0x7, 0xa9, 0x2, 0x2, 0x445, 0x446, 
       0x7, 0x8b, 0x2, 0x2, 0x446, 0x448, 0x5, 0xce, 0x68, 0x2, 0x447, 0x441, 
       0x3, 0x2, 0x2, 0x2, 0x447, 0x444, 0x3, 0x2, 0x2, 0x2, 0x448, 0xcb, 
       0x3, 0x2, 0x2, 0x2, 0x449, 0x44a, 0x7, 0x8b, 0x2, 0x2, 0x44a, 0x44b, 
       0x5, 0xfa, 0x7e, 0x2, 0x44b, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x44d, 
       0x7, 0xb3, 0x2, 0x2, 0x44d, 0x452, 0x5, 0xd0, 0x69, 0x2, 0x44e, 0x44f, 
       0x7, 0x63, 0x2, 0x2, 0x44f, 0x451, 0x5, 0xd0, 0x69, 0x2, 0x450, 0x44e, 
       0x3, 0x2, 0x2, 0x2, 0x451, 0x454, 0x3, 0x2, 0x2, 0x2, 0x452, 0x450, 
       0x3, 0x2, 0x2, 0x2, 0x452, 0x453, 0x3, 0x2, 0x2, 0x2, 0x453, 0xcf, 
       0x3, 0x2, 0x2, 0x2, 0x454, 0x452, 0x3, 0x2, 0x2, 0x2, 0x455, 0x456, 
       0x5, 0x16c, 0xb7, 0x2, 0x456, 0x457, 0x7, 0x6a, 0x2, 0x2, 0x457, 
       0x458, 0x5, 0x120, 0x91, 0x2, 0x458, 0x465, 0x3, 0x2, 0x2, 0x2, 0x459, 
       0x45a, 0x5, 0x164, 0xb3, 0x2, 0x45a, 0x45b, 0x7, 0x6a, 0x2, 0x2, 
       0x45b, 0x45c, 0x5, 0x120, 0x91, 0x2, 0x45c, 0x465, 0x3, 0x2, 0x2, 
       0x2, 0x45d, 0x45e, 0x5, 0x164, 0xb3, 0x2, 0x45e, 0x45f, 0x7, 0x78, 
       0x2, 0x2, 0x45f, 0x460, 0x5, 0x120, 0x91, 0x2, 0x460, 0x465, 0x3, 
       0x2, 0x2, 0x2, 0x461, 0x462, 0x5, 0x164, 0xb3, 0x2, 0x462, 0x463, 
       0x5, 0x118, 0x8d, 0x2, 0x463, 0x465, 0x3, 0x2, 0x2, 0x2, 0x464, 0x455, 
       0x3, 0x2, 0x2, 0x2, 0x464, 0x459, 0x3, 0x2, 0x2, 0x2, 0x464, 0x45d, 
       0x3, 0x2, 0x2, 0x2, 0x464, 0x461, 0x3, 0x2, 0x2, 0x2, 0x465, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x466, 0x468, 0x7, 0x90, 0x2, 0x2, 0x467, 0x466, 
       0x3, 0x2, 0x2, 0x2, 0x467, 0x468, 0x3, 0x2, 0x2, 0x2, 0x468, 0x469, 
       0x3, 0x2, 0x2, 0x2, 0x469, 0x46a, 0x7, 0x8d, 0x2, 0x2, 0x46a, 0x46f, 
       0x5, 0x120, 0x91, 0x2, 0x46b, 0x46c, 0x7, 0x63, 0x2, 0x2, 0x46c, 
       0x46e, 0x5, 0x120, 0x91, 0x2, 0x46d, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46e, 
       0x471, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x46f, 
       0x470, 0x3, 0x2, 0x2, 0x2, 0x470, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x471, 
       0x46f, 0x3, 0x2, 0x2, 0x2, 0x472, 0x473, 0x7, 0xb1, 0x2, 0x2, 0x473, 
       0x478, 0x5, 0xd6, 0x6c, 0x2, 0x474, 0x475, 0x7, 0x63, 0x2, 0x2, 0x475, 
       0x477, 0x5, 0xd6, 0x6c, 0x2, 0x476, 0x474, 0x3, 0x2, 0x2, 0x2, 0x477, 
       0x47a, 0x3, 0x2, 0x2, 0x2, 0x478, 0x476, 0x3, 0x2, 0x2, 0x2, 0x478, 
       0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x47a, 
       0x478, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47c, 0x5, 0x164, 0xb3, 0x2, 0x47c, 
       0x47d, 0x5, 0x118, 0x8d, 0x2, 0x47d, 0x480, 0x3, 0x2, 0x2, 0x2, 0x47e, 
       0x480, 0x5, 0x16c, 0xb7, 0x2, 0x47f, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x47f, 
       0x47e, 0x3, 0x2, 0x2, 0x2, 0x480, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x481, 
       0x483, 0x7, 0xc1, 0x2, 0x2, 0x482, 0x484, 0x7, 0x91, 0x2, 0x2, 0x483, 
       0x482, 0x3, 0x2, 0x2, 0x2, 0x483, 0x484, 0x3, 0x2, 0x2, 0x2, 0x484, 
       0x485, 0x3, 0x2, 0x2, 0x2, 0x485, 0x487, 0x5, 0xea, 0x76, 0x2, 0x486, 
       0x488, 0x5, 0xf8, 0x7d, 0x2, 0x487, 0x486, 0x3, 0x2, 0x2, 0x2, 0x487, 
       0x488, 0x3, 0x2, 0x2, 0x2, 0x488, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x489, 
       0x48b, 0x7, 0xb2, 0x2, 0x2, 0x48a, 0x48c, 0x7, 0x91, 0x2, 0x2, 0x48b, 
       0x48a, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48c, 
       0x48d, 0x3, 0x2, 0x2, 0x2, 0x48d, 0x48e, 0x5, 0xea, 0x76, 0x2, 0x48e, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x490, 0x7, 0x85, 0x2, 0x2, 0x490, 
       0x491, 0x5, 0xde, 0x70, 0x2, 0x491, 0x49a, 0x7, 0x5d, 0x2, 0x2, 0x492, 
       0x497, 0x5, 0x120, 0x91, 0x2, 0x493, 0x494, 0x7, 0x63, 0x2, 0x2, 
       0x494, 0x496, 0x5, 0x120, 0x91, 0x2, 0x495, 0x493, 0x3, 0x2, 0x2, 
       0x2, 0x496, 0x499, 0x3, 0x2, 0x2, 0x2, 0x497, 0x495, 0x3, 0x2, 0x2, 
       0x2, 0x497, 0x498, 0x3, 0x2, 0x2, 0x2, 0x498, 0x49b, 0x3, 0x2, 0x2, 
       0x2, 0x499, 0x497, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x492, 0x3, 0x2, 0x2, 
       0x2, 0x49a, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x49b, 0x49c, 0x3, 0x2, 0x2, 
       0x2, 0x49c, 0x49e, 0x7, 0x5e, 0x2, 0x2, 0x49d, 0x49f, 0x5, 0xe6, 
       0x74, 0x2, 0x49e, 0x49d, 0x3, 0x2, 0x2, 0x2, 0x49e, 0x49f, 0x3, 0x2, 
       0x2, 0x2, 0x49f, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a2, 0x5, 0xe0, 
       0x71, 0x2, 0x4a1, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 0x3, 0x2, 
       0x2, 0x2, 0x4a2, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a8, 0x5, 0x4, 
       0x3, 0x2, 0x4a4, 0x4a5, 0x7, 0x64, 0x2, 0x2, 0x4a5, 0x4a7, 0x5, 0x4, 
       0x3, 0x2, 0x4a6, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a7, 0x4aa, 0x3, 0x2, 
       0x2, 0x2, 0x4a8, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 0x3, 0x2, 
       0x2, 0x2, 0x4a9, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4a8, 0x3, 0x2, 
       0x2, 0x2, 0x4ab, 0x4b5, 0x7, 0xc4, 0x2, 0x2, 0x4ac, 0x4b6, 0x7, 0x74, 
       0x2, 0x2, 0x4ad, 0x4b2, 0x5, 0xe8, 0x75, 0x2, 0x4ae, 0x4af, 0x7, 
       0x63, 0x2, 0x2, 0x4af, 0x4b1, 0x5, 0xe8, 0x75, 0x2, 0x4b0, 0x4ae, 
       0x3, 0x2, 0x2, 0x2, 0x4b1, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b0, 
       0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4b6, 
       0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4ac, 
       0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0xe1, 
       0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4bd, 0x7, 0xa4, 0x2, 0x2, 0x4b8, 0x4be, 
       0x7, 0xbd, 0x2, 0x2, 0x4b9, 0x4ba, 0x7, 0xa0, 0x2, 0x2, 0x4ba, 0x4bb, 
       0x5, 0x142, 0xa2, 0x2, 0x4bb, 0x4bc, 0x9, 0xb, 0x2, 0x2, 0x4bc, 0x4be, 
       0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4b9, 
       0x3, 0x2, 0x2, 0x2, 0x4be, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4c0, 
       0x7, 0xaf, 0x2, 0x2, 0x4c0, 0x4c1, 0x5, 0xe2, 0x72, 0x2, 0x4c1, 0xe5, 
       0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c3, 0x7, 0xad, 0x2, 0x2, 0x4c3, 0x4c4, 
       0x5, 0xe2, 0x72, 0x2, 0x4c4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 
       0x5, 0x164, 0xb3, 0x2, 0x4c6, 0x4c7, 0x7, 0x7f, 0x2, 0x2, 0x4c7, 
       0x4c8, 0x5, 0x164, 0xb3, 0x2, 0x4c8, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4c9, 
       0x4cb, 0x5, 0x164, 0xb3, 0x2, 0x4ca, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4ca, 
       0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x4cc, 
       0x4ce, 0x5, 0xec, 0x77, 0x2, 0x4cd, 0x4cf, 0x5, 0xf0, 0x79, 0x2, 
       0x4ce, 0x4cd, 0x3, 0x2, 0x2, 0x2, 0x4ce, 0x4cf, 0x3, 0x2, 0x2, 0x2, 
       0x4cf, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4d2, 0x5, 0xf2, 0x7a, 
       0x2, 0x4d1, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d2, 0x3, 0x2, 0x2, 
       0x2, 0x4d2, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d3, 0x4d5, 0x5, 0xf4, 0x7b, 
       0x2, 0x4d4, 0x4d3, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 0x3, 0x2, 0x2, 
       0x2, 0x4d5, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4db, 0x7, 0x74, 0x2, 
       0x2, 0x4d7, 0x4d8, 0x7, 0x63, 0x2, 0x2, 0x4d8, 0x4da, 0x5, 0xee, 
       0x78, 0x2, 0x4d9, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4dd, 0x3, 0x2, 
       0x2, 0x2, 0x4db, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4db, 0x4dc, 0x3, 0x2, 
       0x2, 0x2, 0x4dc, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4db, 0x3, 0x2, 
       0x2, 0x2, 0x4de, 0x4e3, 0x5, 0xee, 0x78, 0x2, 0x4df, 0x4e0, 0x7, 
       0x63, 0x2, 0x2, 0x4e0, 0x4e2, 0x5, 0xee, 0x78, 0x2, 0x4e1, 0x4df, 
       0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e5, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4e1, 
       0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e7, 
       0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4d6, 
       0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0xed, 
       0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e9, 0x5, 0x120, 0x91, 0x2, 0x4e9, 0x4ea, 
       0x7, 0x7f, 0x2, 0x2, 0x4ea, 0x4eb, 0x5, 0x164, 0xb3, 0x2, 0x4eb, 
       0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4ee, 0x5, 0x120, 0x91, 0x2, 0x4ed, 
       0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4ed, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4ee, 
       0xef, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x7, 0xac, 0x2, 0x2, 0x4f0, 
       0x4f1, 0x7, 0x84, 0x2, 0x2, 0x4f1, 0x4f6, 0x5, 0xf6, 0x7c, 0x2, 0x4f2, 
       0x4f3, 0x7, 0x63, 0x2, 0x2, 0x4f3, 0x4f5, 0x5, 0xf6, 0x7c, 0x2, 0x4f4, 
       0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4f6, 
       0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f7, 
       0xf1, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 
       0x4fa, 0x7, 0xa1, 0x2, 0x2, 0x4fa, 0x4fb, 0x5, 0x120, 0x91, 0x2, 
       0x4fb, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 0x7, 0xa0, 0x2, 0x2, 
       0x4fd, 0x4fe, 0x5, 0x120, 0x91, 0x2, 0x4fe, 0xf5, 0x3, 0x2, 0x2, 
       0x2, 0x4ff, 0x501, 0x5, 0x120, 0x91, 0x2, 0x500, 0x502, 0x9, 0xc, 
       0x2, 0x2, 0x501, 0x500, 0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x3, 0x2, 
       0x2, 0x2, 0x502, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x503, 0x504, 0x7, 0xc0, 
       0x2, 0x2, 0x504, 0x505, 0x5, 0x120, 0x91, 0x2, 0x505, 0xf9, 0x3, 
       0x2, 0x2, 0x2, 0x506, 0x50b, 0x5, 0xfc, 0x7f, 0x2, 0x507, 0x508, 
       0x7, 0x63, 0x2, 0x2, 0x508, 0x50a, 0x5, 0xfc, 0x7f, 0x2, 0x509, 0x507, 
       0x3, 0x2, 0x2, 0x2, 0x50a, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x50b, 0x509, 
       0x3, 0x2, 0x2, 0x2, 0x50b, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x50c, 0xfb, 
       0x3, 0x2, 0x2, 0x2, 0x50d, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x50f, 
       0x5, 0x164, 0xb3, 0x2, 0x50f, 0x510, 0x7, 0x6a, 0x2, 0x2, 0x510, 
       0x511, 0x5, 0xfe, 0x80, 0x2, 0x511, 0x514, 0x3, 0x2, 0x2, 0x2, 0x512, 
       0x514, 0x5, 0xfe, 0x80, 0x2, 0x513, 0x50e, 0x3, 0x2, 0x2, 0x2, 0x513, 
       0x512, 0x3, 0x2, 0x2, 0x2, 0x514, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x515, 
       0x516, 0x5, 0x100, 0x81, 0x2, 0x516, 0xff, 0x3, 0x2, 0x2, 0x2, 0x517, 
       0x51b, 0x5, 0x102, 0x82, 0x2, 0x518, 0x51a, 0x5, 0x104, 0x83, 0x2, 
       0x519, 0x518, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x51d, 0x3, 0x2, 0x2, 0x2, 
       0x51b, 0x519, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51c, 0x3, 0x2, 0x2, 0x2, 
       0x51c, 0x523, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51b, 0x3, 0x2, 0x2, 0x2, 
       0x51e, 0x51f, 0x7, 0x5d, 0x2, 0x2, 0x51f, 0x520, 0x5, 0x100, 0x81, 
       0x2, 0x520, 0x521, 0x7, 0x5e, 0x2, 0x2, 0x521, 0x523, 0x3, 0x2, 0x2, 
       0x2, 0x522, 0x517, 0x3, 0x2, 0x2, 0x2, 0x522, 0x51e, 0x3, 0x2, 0x2, 
       0x2, 0x523, 0x101, 0x3, 0x2, 0x2, 0x2, 0x524, 0x526, 0x7, 0x5d, 0x2, 
       0x2, 0x525, 0x527, 0x5, 0x164, 0xb3, 0x2, 0x526, 0x525, 0x3, 0x2, 
       0x2, 0x2, 0x526, 0x527, 0x3, 0x2, 0x2, 0x2, 0x527, 0x529, 0x3, 0x2, 
       0x2, 0x2, 0x528, 0x52a, 0x5, 0x118, 0x8d, 0x2, 0x529, 0x528, 0x3, 
       0x2, 0x2, 0x2, 0x529, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52c, 0x3, 
       0x2, 0x2, 0x2, 0x52b, 0x52d, 0x5, 0x114, 0x8b, 0x2, 0x52c, 0x52b, 
       0x3, 0x2, 0x2, 0x2, 0x52c, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x52e, 
       0x3, 0x2, 0x2, 0x2, 0x52e, 0x52f, 0x7, 0x5e, 0x2, 0x2, 0x52f, 0x103, 
       0x3, 0x2, 0x2, 0x2, 0x530, 0x531, 0x5, 0x106, 0x84, 0x2, 0x531, 0x532, 
       0x5, 0x102, 0x82, 0x2, 0x532, 0x105, 0x3, 0x2, 0x2, 0x2, 0x533, 0x534, 
       0x5, 0x108, 0x85, 0x2, 0x534, 0x536, 0x5, 0x10c, 0x87, 0x2, 0x535, 
       0x537, 0x5, 0x10e, 0x88, 0x2, 0x536, 0x535, 0x3, 0x2, 0x2, 0x2, 0x536, 
       0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 0x538, 0x3, 0x2, 0x2, 0x2, 0x538, 
       0x539, 0x5, 0x10c, 0x87, 0x2, 0x539, 0x53a, 0x5, 0x10a, 0x86, 0x2, 
       0x53a, 0x550, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x53c, 0x5, 0x108, 0x85, 
       0x2, 0x53c, 0x53e, 0x5, 0x10c, 0x87, 0x2, 0x53d, 0x53f, 0x5, 0x10e, 
       0x88, 0x2, 0x53e, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x53f, 0x3, 0x2, 
       0x2, 0x2, 0x53f, 0x540, 0x3, 0x2, 0x2, 0x2, 0x540, 0x541, 0x5, 0x10c, 
       0x87, 0x2, 0x541, 0x550, 0x3, 0x2, 0x2, 0x2, 0x542, 0x544, 0x5, 0x10c, 
       0x87, 0x2, 0x543, 0x545, 0x5, 0x10e, 0x88, 0x2, 0x544, 0x543, 0x3, 
       0x2, 0x2, 0x2, 0x544, 0x545, 0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 0x3, 
       0x2, 0x2, 0x2, 0x546, 0x547, 0x5, 0x10c, 0x87, 0x2, 0x547, 0x548, 
       0x5, 0x10a, 0x86, 0x2, 0x548, 0x550, 0x3, 0x2, 0x2, 0x2, 0x549, 0x54b, 
       0x5, 0x10c, 0x87, 0x2, 0x54a, 0x54c, 0x5, 0x10e, 0x88, 0x2, 0x54b, 
       0x54a, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54c, 
       0x54d, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54e, 0x5, 0x10c, 0x87, 0x2, 0x54e, 
       0x550, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x533, 0x3, 0x2, 0x2, 0x2, 0x54f, 
       0x53b, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x542, 0x3, 0x2, 0x2, 0x2, 0x54f, 
       0x549, 0x3, 0x2, 0x2, 0x2, 0x550, 0x107, 0x3, 0x2, 0x2, 0x2, 0x551, 
       0x552, 0x9, 0xd, 0x2, 0x2, 0x552, 0x109, 0x3, 0x2, 0x2, 0x2, 0x553, 
       0x554, 0x9, 0xe, 0x2, 0x2, 0x554, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x555, 
       0x556, 0x9, 0xf, 0x2, 0x2, 0x556, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x557, 
       0x559, 0x7, 0x5f, 0x2, 0x2, 0x558, 0x55a, 0x5, 0x164, 0xb3, 0x2, 
       0x559, 0x558, 0x3, 0x2, 0x2, 0x2, 0x559, 0x55a, 0x3, 0x2, 0x2, 0x2, 
       0x55a, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x55d, 0x5, 0x116, 0x8c, 
       0x2, 0x55c, 0x55b, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55d, 0x3, 0x2, 0x2, 
       0x2, 0x55d, 0x55f, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x560, 0x5, 0x112, 
       0x8a, 0x2, 0x55f, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x560, 0x3, 0x2, 
       0x2, 0x2, 0x560, 0x561, 0x3, 0x2, 0x2, 0x2, 0x561, 0x562, 0x5, 0x114, 
       0x8b, 0x2, 0x562, 0x563, 0x7, 0x60, 0x2, 0x2, 0x563, 0x591, 0x3, 
       0x2, 0x2, 0x2, 0x564, 0x566, 0x7, 0x5f, 0x2, 0x2, 0x565, 0x567, 0x5, 
       0x164, 0xb3, 0x2, 0x566, 0x565, 0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 
       0x3, 0x2, 0x2, 0x2, 0x567, 0x569, 0x3, 0x2, 0x2, 0x2, 0x568, 0x56a, 
       0x5, 0x116, 0x8c, 0x2, 0x569, 0x568, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 
       0x3, 0x2, 0x2, 0x2, 0x56a, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56d, 
       0x5, 0x112, 0x8a, 0x2, 0x56c, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 
       0x3, 0x2, 0x2, 0x2, 0x56d, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x570, 
       0x5, 0x110, 0x89, 0x2, 0x56f, 0x571, 0x5, 0x164, 0xb3, 0x2, 0x570, 
       0x56f, 0x3, 0x2, 0x2, 0x2, 0x570, 0x571, 0x3, 0x2, 0x2, 0x2, 0x571, 
       0x573, 0x3, 0x2, 0x2, 0x2, 0x572, 0x574, 0x5, 0x110, 0x89, 0x2, 0x573, 
       0x572, 0x3, 0x2, 0x2, 0x2, 0x573, 0x574, 0x3, 0x2, 0x2, 0x2, 0x574, 
       0x575, 0x3, 0x2, 0x2, 0x2, 0x575, 0x576, 0x7, 0x60, 0x2, 0x2, 0x576, 
       0x591, 0x3, 0x2, 0x2, 0x2, 0x577, 0x579, 0x7, 0x5f, 0x2, 0x2, 0x578, 
       0x57a, 0x5, 0x164, 0xb3, 0x2, 0x579, 0x578, 0x3, 0x2, 0x2, 0x2, 0x579, 
       0x57a, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x57b, 
       0x57d, 0x5, 0x116, 0x8c, 0x2, 0x57c, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x57c, 
       0x57d, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x57f, 0x3, 0x2, 0x2, 0x2, 0x57e, 
       0x580, 0x5, 0x112, 0x8a, 0x2, 0x57f, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x57f, 
       0x580, 0x3, 0x2, 0x2, 0x2, 0x580, 0x584, 0x3, 0x2, 0x2, 0x2, 0x581, 
       0x583, 0x5, 0x114, 0x8b, 0x2, 0x582, 0x581, 0x3, 0x2, 0x2, 0x2, 0x583, 
       0x586, 0x3, 0x2, 0x2, 0x2, 0x584, 0x582, 0x3, 0x2, 0x2, 0x2, 0x584, 
       0x585, 0x3, 0x2, 0x2, 0x2, 0x585, 0x58a, 0x3, 0x2, 0x2, 0x2, 0x586, 
       0x584, 0x3, 0x2, 0x2, 0x2, 0x587, 0x588, 0x5, 0x110, 0x89, 0x2, 0x588, 
       0x589, 0x5, 0x164, 0xb3, 0x2, 0x589, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58a, 
       0x587, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58b, 
       0x58d, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58e, 0x5, 0x110, 0x89, 0x2, 0x58d, 
       0x58c, 0x3, 0x2, 0x2, 0x2, 0x58d, 0x58e, 0x3, 0x2, 0x2, 0x2, 0x58e, 
       0x58f, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x591, 0x7, 0x60, 0x2, 0x2, 0x590, 
       0x557, 0x3, 0x2, 0x2, 0x2, 0x590, 0x564, 0x3, 0x2, 0x2, 0x2, 0x590, 
       0x577, 0x3, 0x2, 0x2, 0x2, 0x591, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x592, 
       0x593, 0x7, 0x5d, 0x2, 0x2, 0x593, 0x594, 0x5, 0x164, 0xb3, 0x2, 
       0x594, 0x595, 0x7, 0x63, 0x2, 0x2, 0x595, 0x596, 0x5, 0x164, 0xb3, 
       0x2, 0x596, 0x597, 0x7, 0x69, 0x2, 0x2, 0x597, 0x598, 0x5, 0x120, 
       0x91, 0x2, 0x598, 0x599, 0x7, 0x5e, 0x2, 0x2, 0x599, 0x111, 0x3, 
       0x2, 0x2, 0x2, 0x59a, 0x59c, 0x7, 0x74, 0x2, 0x2, 0x59b, 0x59d, 0x9, 
       0x10, 0x2, 0x2, 0x59c, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x59d, 0x3, 
       0x2, 0x2, 0x2, 0x59d, 0x59f, 0x3, 0x2, 0x2, 0x2, 0x59e, 0x5a0, 0x5, 
       0x120, 0x91, 0x2, 0x59f, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x59f, 0x5a0, 
       0x3, 0x2, 0x2, 0x2, 0x5a0, 0x5a5, 0x3, 0x2, 0x2, 0x2, 0x5a1, 0x5a3, 
       0x7, 0x65, 0x2, 0x2, 0x5a2, 0x5a4, 0x5, 0x120, 0x91, 0x2, 0x5a3, 
       0x5a2, 0x3, 0x2, 0x2, 0x2, 0x5a3, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a4, 
       0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5a5, 0x5a1, 0x3, 0x2, 0x2, 0x2, 0x5a5, 
       0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5a6, 0x113, 0x3, 0x2, 0x2, 0x2, 0x5a7, 
       0x5aa, 0x5, 0x168, 0xb5, 0x2, 0x5a8, 0x5aa, 0x5, 0x16a, 0xb6, 0x2, 
       0x5a9, 0x5a7, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5a8, 0x3, 0x2, 0x2, 0x2, 
       0x5aa, 0x115, 0x3, 0x2, 0x2, 0x2, 0x5ab, 0x5ac, 0x7, 0x66, 0x2, 0x2, 
       0x5ac, 0x5b4, 0x5, 0x11e, 0x90, 0x2, 0x5ad, 0x5af, 0x7, 0x69, 0x2, 
       0x2, 0x5ae, 0x5b0, 0x7, 0x66, 0x2, 0x2, 0x5af, 0x5ae, 0x3, 0x2, 0x2, 
       0x2, 0x5af, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5b1, 0x3, 0x2, 0x2, 
       0x2, 0x5b1, 0x5b3, 0x5, 0x11e, 0x90, 0x2, 0x5b2, 0x5ad, 0x3, 0x2, 
       0x2, 0x2, 0x5b3, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b2, 0x3, 0x2, 
       0x2, 0x2, 0x5b4, 0x5b5, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0x117, 0x3, 0x2, 
       0x2, 0x2, 0x5b6, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5bb, 0x5, 0x11a, 
       0x8e, 0x2, 0x5b8, 0x5ba, 0x5, 0x11a, 0x8e, 0x2, 0x5b9, 0x5b8, 0x3, 
       0x2, 0x2, 0x2, 0x5ba, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5b9, 0x3, 
       0x2, 0x2, 0x2, 0x5bb, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x119, 0x3, 
       0x2, 0x2, 0x2, 0x5bd, 0x5bb, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x5bf, 0x7, 
       0x66, 0x2, 0x2, 0x5bf, 0x5c0, 0x5, 0x11c, 0x8f, 0x2, 0x5c0, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5c2, 0x5, 0x4, 0x3, 0x2, 0x5c2, 0x11d, 
       0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c4, 0x5, 0x4, 0x3, 0x2, 0x5c4, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c6, 0x5, 0x122, 0x92, 0x2, 0x5c6, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5cc, 0x5, 0x124, 0x93, 0x2, 0x5c8, 0x5c9, 
       0x7, 0xab, 0x2, 0x2, 0x5c9, 0x5cb, 0x5, 0x124, 0x93, 0x2, 0x5ca, 
       0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5ce, 0x3, 0x2, 0x2, 0x2, 0x5cc, 
       0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5cd, 
       0x123, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5cf, 
       0x5d4, 0x5, 0x126, 0x94, 0x2, 0x5d0, 0x5d1, 0x7, 0xc3, 0x2, 0x2, 
       0x5d1, 0x5d3, 0x5, 0x126, 0x94, 0x2, 0x5d2, 0x5d0, 0x3, 0x2, 0x2, 
       0x2, 0x5d3, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0x5d4, 0x5d2, 0x3, 0x2, 0x2, 
       0x2, 0x5d4, 0x5d5, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x125, 0x3, 0x2, 0x2, 
       0x2, 0x5d6, 0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5d7, 0x5dc, 0x5, 0x128, 
       0x95, 0x2, 0x5d8, 0x5d9, 0x7, 0x7d, 0x2, 0x2, 0x5d9, 0x5db, 0x5, 
       0x128, 0x95, 0x2, 0x5da, 0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5db, 0x5de, 
       0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5dd, 
       0x3, 0x2, 0x2, 0x2, 0x5dd, 0x127, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5dc, 
       0x3, 0x2, 0x2, 0x2, 0x5df, 0x5e1, 0x7, 0xa8, 0x2, 0x2, 0x5e0, 0x5df, 
       0x3, 0x2, 0x2, 0x2, 0x5e1, 0x5e4, 0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e0, 
       0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e3, 0x3, 0x2, 0x2, 0x2, 0x5e3, 0x5e5, 
       0x3, 0x2, 0x2, 0x2, 0x5e4, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e5, 0x5e6, 
       0x5, 0x12a, 0x96, 0x2, 0x5e6, 0x129, 0x3, 0x2, 0x2, 0x2, 0x5e7, 0x5eb, 
       0x5, 0x12c, 0x97, 0x2, 0x5e8, 0x5ea, 0x5, 0x148, 0xa5, 0x2, 0x5e9, 
       0x5e8, 0x3, 0x2, 0x2, 0x2, 0x5ea, 0x5ed, 0x3, 0x2, 0x2, 0x2, 0x5eb, 
       0x5e9, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5ec, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x5ed, 0x5eb, 0x3, 0x2, 0x2, 0x2, 0x5ee, 
       0x5f5, 0x5, 0x12e, 0x98, 0x2, 0x5ef, 0x5f0, 0x7, 0x72, 0x2, 0x2, 
       0x5f0, 0x5f4, 0x5, 0x12e, 0x98, 0x2, 0x5f1, 0x5f2, 0x7, 0x73, 0x2, 
       0x2, 0x5f2, 0x5f4, 0x5, 0x12e, 0x98, 0x2, 0x5f3, 0x5ef, 0x3, 0x2, 
       0x2, 0x2, 0x5f3, 0x5f1, 0x3, 0x2, 0x2, 0x2, 0x5f4, 0x5f7, 0x3, 0x2, 
       0x2, 0x2, 0x5f5, 0x5f3, 0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5f6, 0x3, 0x2, 
       0x2, 0x2, 0x5f6, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f5, 0x3, 0x2, 
       0x2, 0x2, 0x5f8, 0x601, 0x5, 0x130, 0x99, 0x2, 0x5f9, 0x5fa, 0x7, 
       0x74, 0x2, 0x2, 0x5fa, 0x600, 0x5, 0x130, 0x99, 0x2, 0x5fb, 0x5fc, 
       0x7, 0x75, 0x2, 0x2, 0x5fc, 0x600, 0x5, 0x130, 0x99, 0x2, 0x5fd, 
       0x5fe, 0x7, 0x76, 0x2, 0x2, 0x5fe, 0x600, 0x5, 0x130, 0x99, 0x2, 
       0x5ff, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5ff, 0x5fb, 0x3, 0x2, 0x2, 0x2, 
       0x5ff, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x600, 0x603, 0x3, 0x2, 0x2, 0x2, 
       0x601, 0x5ff, 0x3, 0x2, 0x2, 0x2, 0x601, 0x602, 0x3, 0x2, 0x2, 0x2, 
       0x602, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x603, 0x601, 0x3, 0x2, 0x2, 0x2, 
       0x604, 0x609, 0x5, 0x132, 0x9a, 0x2, 0x605, 0x606, 0x7, 0x77, 0x2, 
       0x2, 0x606, 0x608, 0x5, 0x132, 0x9a, 0x2, 0x607, 0x605, 0x3, 0x2, 
       0x2, 0x2, 0x608, 0x60b, 0x3, 0x2, 0x2, 0x2, 0x609, 0x607, 0x3, 0x2, 
       0x2, 0x2, 0x609, 0x60a, 0x3, 0x2, 0x2, 0x2, 0x60a, 0x131, 0x3, 0x2, 
       0x2, 0x2, 0x60b, 0x609, 0x3, 0x2, 0x2, 0x2, 0x60c, 0x60e, 0x9, 0x11, 
       0x2, 0x2, 0x60d, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x60e, 0x611, 0x3, 0x2, 
       0x2, 0x2, 0x60f, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x60f, 0x610, 0x3, 0x2, 
       0x2, 0x2, 0x610, 0x612, 0x3, 0x2, 0x2, 0x2, 0x611, 0x60f, 0x3, 0x2, 
       0x2, 0x2, 0x612, 0x613, 0x5, 0x134, 0x9b, 0x2, 0x613, 0x133, 0x3, 
       0x2, 0x2, 0x2, 0x614, 0x618, 0x5, 0x138, 0x9d, 0x2, 0x615, 0x617, 
       0x5, 0x136, 0x9c, 0x2, 0x616, 0x615, 0x3, 0x2, 0x2, 0x2, 0x617, 0x61a, 
       0x3, 0x2, 0x2, 0x2, 0x618, 0x616, 0x3, 0x2, 0x2, 0x2, 0x618, 0x619, 
       0x3, 0x2, 0x2, 0x2, 0x619, 0x135, 0x3, 0x2, 0x2, 0x2, 0x61a, 0x618, 
       0x3, 0x2, 0x2, 0x2, 0x61b, 0x623, 0x7, 0x71, 0x2, 0x2, 0x61c, 0x623, 
       0x7, 0x9a, 0x2, 0x2, 0x61d, 0x61e, 0x7, 0xb6, 0x2, 0x2, 0x61e, 0x623, 
       0x7, 0xc1, 0x2, 0x2, 0x61f, 0x620, 0x7, 0x94, 0x2, 0x2, 0x620, 0x623, 
       0x7, 0xc1, 0x2, 0x2, 0x621, 0x623, 0x7, 0x89, 0x2, 0x2, 0x622, 0x61b, 
       0x3, 0x2, 0x2, 0x2, 0x622, 0x61c, 0x3, 0x2, 0x2, 0x2, 0x622, 0x61d, 
       0x3, 0x2, 0x2, 0x2, 0x622, 0x61f, 0x3, 0x2, 0x2, 0x2, 0x622, 0x621, 
       0x3, 0x2, 0x2, 0x2, 0x623, 0x624, 0x3, 0x2, 0x2, 0x2, 0x624, 0x62b, 
       0x5, 0x138, 0x9d, 0x2, 0x625, 0x626, 0x7, 0x9d, 0x2, 0x2, 0x626, 
       0x62b, 0x7, 0x8c, 0x2, 0x2, 0x627, 0x628, 0x7, 0x9d, 0x2, 0x2, 0x628, 
       0x629, 0x7, 0xa8, 0x2, 0x2, 0x629, 0x62b, 0x7, 0x8c, 0x2, 0x2, 0x62a, 
       0x622, 0x3, 0x2, 0x2, 0x2, 0x62a, 0x625, 0x3, 0x2, 0x2, 0x2, 0x62a, 
       0x627, 0x3, 0x2, 0x2, 0x2, 0x62b, 0x137, 0x3, 0x2, 0x2, 0x2, 0x62c, 
       0x630, 0x5, 0x13c, 0x9f, 0x2, 0x62d, 0x62f, 0x5, 0x13a, 0x9e, 0x2, 
       0x62e, 0x62d, 0x3, 0x2, 0x2, 0x2, 0x62f, 0x632, 0x3, 0x2, 0x2, 0x2, 
       0x630, 0x62e, 0x3, 0x2, 0x2, 0x2, 0x630, 0x631, 0x3, 0x2, 0x2, 0x2, 
       0x631, 0x139, 0x3, 0x2, 0x2, 0x2, 0x632, 0x630, 0x3, 0x2, 0x2, 0x2, 
       0x633, 0x634, 0x7, 0x5f, 0x2, 0x2, 0x634, 0x635, 0x5, 0x120, 0x91, 
       0x2, 0x635, 0x636, 0x7, 0x60, 0x2, 0x2, 0x636, 0x641, 0x3, 0x2, 0x2, 
       0x2, 0x637, 0x639, 0x7, 0x5f, 0x2, 0x2, 0x638, 0x63a, 0x5, 0x120, 
       0x91, 0x2, 0x639, 0x638, 0x3, 0x2, 0x2, 0x2, 0x639, 0x63a, 0x3, 0x2, 
       0x2, 0x2, 0x63a, 0x63b, 0x3, 0x2, 0x2, 0x2, 0x63b, 0x63d, 0x7, 0x65, 
       0x2, 0x2, 0x63c, 0x63e, 0x5, 0x120, 0x91, 0x2, 0x63d, 0x63c, 0x3, 
       0x2, 0x2, 0x2, 0x63d, 0x63e, 0x3, 0x2, 0x2, 0x2, 0x63e, 0x63f, 0x3, 
       0x2, 0x2, 0x2, 0x63f, 0x641, 0x7, 0x60, 0x2, 0x2, 0x640, 0x633, 0x3, 
       0x2, 0x2, 0x2, 0x640, 0x637, 0x3, 0x2, 0x2, 0x2, 0x641, 0x13b, 0x3, 
       0x2, 0x2, 0x2, 0x642, 0x644, 0x5, 0x13e, 0xa0, 0x2, 0x643, 0x645, 
       0x5, 0x118, 0x8d, 0x2, 0x644, 0x643, 0x3, 0x2, 0x2, 0x2, 0x644, 0x645, 
       0x3, 0x2, 0x2, 0x2, 0x645, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x646, 0x64a, 
       0x5, 0x140, 0xa1, 0x2, 0x647, 0x649, 0x5, 0x15e, 0xb0, 0x2, 0x648, 
       0x647, 0x3, 0x2, 0x2, 0x2, 0x649, 0x64c, 0x3, 0x2, 0x2, 0x2, 0x64a, 
       0x648, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x64b, 0x3, 0x2, 0x2, 0x2, 0x64b, 
       0x13f, 0x3, 0x2, 0x2, 0x2, 0x64c, 0x64a, 0x3, 0x2, 0x2, 0x2, 0x64d, 
       0x68a, 0x5, 0x142, 0xa2, 0x2, 0x64e, 0x68a, 0x5, 0x16a, 0xb6, 0x2, 
       0x64f, 0x68a, 0x5, 0x160, 0xb1, 0x2, 0x650, 0x651, 0x7, 0x8a, 0x2, 
       0x2, 0x651, 0x652, 0x7, 0x5d, 0x2, 0x2, 0x652, 0x653, 0x7, 0x74, 
       0x2, 0x2, 0x653, 0x68a, 0x7, 0x5e, 0x2, 0x2, 0x654, 0x68a, 0x5, 0x15a, 
       0xae, 0x2, 0x655, 0x68a, 0x5, 0x15c, 0xaf, 0x2, 0x656, 0x657, 0x7, 
       0x99, 0x2, 0x2, 0x657, 0x658, 0x7, 0x5d, 0x2, 0x2, 0x658, 0x659, 
       0x5, 0x14e, 0xa8, 0x2, 0x659, 0x65a, 0x7, 0x5e, 0x2, 0x2, 0x65a, 
       0x68a, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x65c, 0x7, 0x97, 0x2, 0x2, 0x65c, 
       0x65d, 0x7, 0x5d, 0x2, 0x2, 0x65d, 0x65e, 0x5, 0x152, 0xaa, 0x2, 
       0x65e, 0x65f, 0x7, 0x5e, 0x2, 0x2, 0x65f, 0x68a, 0x3, 0x2, 0x2, 0x2, 
       0x660, 0x661, 0x7, 0xb0, 0x2, 0x2, 0x661, 0x662, 0x7, 0x5d, 0x2, 
       0x2, 0x662, 0x663, 0x5, 0x150, 0xa9, 0x2, 0x663, 0x664, 0x7, 0x5e, 
       0x2, 0x2, 0x664, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 0x7, 0x87, 
       0x2, 0x2, 0x666, 0x667, 0x7, 0x5d, 0x2, 0x2, 0x667, 0x66c, 0x5, 0x120, 
       0x91, 0x2, 0x668, 0x669, 0x7, 0x63, 0x2, 0x2, 0x669, 0x66b, 0x5, 
       0x120, 0x91, 0x2, 0x66a, 0x668, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66e, 
       0x3, 0x2, 0x2, 0x2, 0x66c, 0x66a, 0x3, 0x2, 0x2, 0x2, 0x66c, 0x66d, 
       0x3, 0x2, 0x2, 0x2, 0x66d, 0x66f, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66c, 
       0x3, 0x2, 0x2, 0x2, 0x66f, 0x670, 0x7, 0x5e, 0x2, 0x2, 0x670, 0x68a, 
       0x3, 0x2, 0x2, 0x2, 0x671, 0x672, 0x7, 0x7c, 0x2, 0x2, 0x672, 0x673, 
       0x7, 0x5d, 0x2, 0x2, 0x673, 0x674, 0x5, 0x14e, 0xa8, 0x2, 0x674, 
       0x675, 0x7, 0x5e, 0x2, 0x2, 0x675, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x676, 
       0x677, 0x7, 0x7e, 0x2, 0x2, 0x677, 0x678, 0x7, 0x5d, 0x2, 0x2, 0x678, 
       0x679, 0x5, 0x14e, 0xa8, 0x2, 0x679, 0x67a, 0x7, 0x5e, 0x2, 0x2, 
       0x67a, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67c, 0x7, 0xa7, 0x2, 0x2, 
       0x67c, 0x67d, 0x7, 0x5d, 0x2, 0x2, 0x67d, 0x67e, 0x5, 0x14e, 0xa8, 
       0x2, 0x67e, 0x67f, 0x7, 0x5e, 0x2, 0x2, 0x67f, 0x68a, 0x3, 0x2, 0x2, 
       0x2, 0x680, 0x681, 0x7, 0xb5, 0x2, 0x2, 0x681, 0x682, 0x7, 0x5d, 
       0x2, 0x2, 0x682, 0x683, 0x5, 0x14e, 0xa8, 0x2, 0x683, 0x684, 0x7, 
       0x5e, 0x2, 0x2, 0x684, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x685, 0x68a, 0x5, 
       0x14c, 0xa7, 0x2, 0x686, 0x68a, 0x5, 0x14a, 0xa6, 0x2, 0x687, 0x68a, 
       0x5, 0x156, 0xac, 0x2, 0x688, 0x68a, 0x5, 0x164, 0xb3, 0x2, 0x689, 
       0x64d, 0x3, 0x2, 0x2, 0x2, 0x689, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x64f, 0x3, 0x2, 0x2, 0x2, 0x689, 0x650, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x654, 0x3, 0x2, 0x2, 0x2, 0x689, 0x655, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x656, 0x3, 0x2, 0x2, 0x2, 0x689, 0x65b, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x660, 0x3, 0x2, 0x2, 0x2, 0x689, 0x665, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x671, 0x3, 0x2, 0x2, 0x2, 0x689, 0x676, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x67b, 0x3, 0x2, 0x2, 0x2, 0x689, 0x680, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x685, 0x3, 0x2, 0x2, 0x2, 0x689, 0x686, 0x3, 0x2, 0x2, 0x2, 0x689, 
       0x687, 0x3, 0x2, 0x2, 0x2, 0x689, 0x688, 0x3, 0x2, 0x2, 0x2, 0x68a, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x692, 0x5, 0x166, 0xb4, 0x2, 0x68c, 
       0x692, 0x7, 0xc5, 0x2, 0x2, 0x68d, 0x692, 0x5, 0x144, 0xa3, 0x2, 
       0x68e, 0x692, 0x7, 0x8c, 0x2, 0x2, 0x68f, 0x692, 0x5, 0x168, 0xb5, 
       0x2, 0x690, 0x692, 0x5, 0x146, 0xa4, 0x2, 0x691, 0x68b, 0x3, 0x2, 
       0x2, 0x2, 0x691, 0x68c, 0x3, 0x2, 0x2, 0x2, 0x691, 0x68d, 0x3, 0x2, 
       0x2, 0x2, 0x691, 0x68e, 0x3, 0x2, 0x2, 0x2, 0x691, 0x68f, 0x3, 0x2, 
       0x2, 0x2, 0x691, 0x690, 0x3, 0x2, 0x2, 0x2, 0x692, 0x143, 0x3, 0x2, 
       0x2, 0x2, 0x693, 0x694, 0x9, 0x12, 0x2, 0x2, 0x694, 0x145, 0x3, 0x2, 
       0x2, 0x2, 0x695, 0x69e, 0x7, 0x5f, 0x2, 0x2, 0x696, 0x69b, 0x5, 0x120, 
       0x91, 0x2, 0x697, 0x698, 0x7, 0x63, 0x2, 0x2, 0x698, 0x69a, 0x5, 
       0x120, 0x91, 0x2, 0x699, 0x697, 0x3, 0x2, 0x2, 0x2, 0x69a, 0x69d, 
       0x3, 0x2, 0x2, 0x2, 0x69b, 0x699, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69c, 
       0x3, 0x2, 0x2, 0x2, 0x69c, 0x69f, 0x3, 0x2, 0x2, 0x2, 0x69d, 0x69b, 
       0x3, 0x2, 0x2, 0x2, 0x69e, 0x696, 0x3, 0x2, 0x2, 0x2, 0x69e, 0x69f, 
       0x3, 0x2, 0x2, 0x2, 0x69f, 0x6a0, 0x3, 0x2, 0x2, 0x2, 0x6a0, 0x6a1, 
       0x7, 0x60, 0x2, 0x2, 0x6a1, 0x147, 0x3, 0x2, 0x2, 0x2, 0x6a2, 0x6a3, 
       0x7, 0x6a, 0x2, 0x2, 0x6a3, 0x6b1, 0x5, 0x12c, 0x97, 0x2, 0x6a4, 
       0x6a5, 0x7, 0x6f, 0x2, 0x2, 0x6a5, 0x6b1, 0x5, 0x12c, 0x97, 0x2, 
       0x6a6, 0x6a7, 0x7, 0x70, 0x2, 0x2, 0x6a7, 0x6b1, 0x5, 0x12c, 0x97, 
       0x2, 0x6a8, 0x6a9, 0x7, 0x6b, 0x2, 0x2, 0x6a9, 0x6b1, 0x5, 0x12c, 
       0x97, 0x2, 0x6aa, 0x6ab, 0x7, 0x6c, 0x2, 0x2, 0x6ab, 0x6b1, 0x5, 
       0x12c, 0x97, 0x2, 0x6ac, 0x6ad, 0x7, 0x6d, 0x2, 0x2, 0x6ad, 0x6b1, 
       0x5, 0x12c, 0x97, 0x2, 0x6ae, 0x6af, 0x7, 0x6e, 0x2, 0x2, 0x6af, 
       0x6b1, 0x5, 0x12c, 0x97, 0x2, 0x6b0, 0x6a2, 0x3, 0x2, 0x2, 0x2, 0x6b0, 
       0x6a4, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x6b0, 
       0x6a8, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6aa, 0x3, 0x2, 0x2, 0x2, 0x6b0, 
       0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6ae, 0x3, 0x2, 0x2, 0x2, 0x6b1, 
       0x149, 0x3, 0x2, 0x2, 0x2, 0x6b2, 0x6b3, 0x7, 0x5d, 0x2, 0x2, 0x6b3, 
       0x6b4, 0x5, 0x120, 0x91, 0x2, 0x6b4, 0x6b5, 0x7, 0x5e, 0x2, 0x2, 
       0x6b5, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6b8, 0x5, 0x102, 0x82, 
       0x2, 0x6b7, 0x6b9, 0x5, 0x104, 0x83, 0x2, 0x6b8, 0x6b7, 0x3, 0x2, 
       0x2, 0x2, 0x6b9, 0x6ba, 0x3, 0x2, 0x2, 0x2, 0x6ba, 0x6b8, 0x3, 0x2, 
       0x2, 0x2, 0x6ba, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6bb, 0x14d, 0x3, 0x2, 
       0x2, 0x2, 0x6bc, 0x6be, 0x5, 0x154, 0xab, 0x2, 0x6bd, 0x6bf, 0x5, 
       0xf8, 0x7d, 0x2, 0x6be, 0x6bd, 0x3, 0x2, 0x2, 0x2, 0x6be, 0x6bf, 
       0x3, 0x2, 0x2, 0x2, 0x6bf, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x6c0, 0x6c1, 
       0x5, 0x164, 0xb3, 0x2, 0x6c1, 0x6c2, 0x7, 0x6a, 0x2, 0x2, 0x6c2, 
       0x6c3, 0x5, 0x120, 0x91, 0x2, 0x6c3, 0x6c4, 0x7, 0x63, 0x2, 0x2, 
       0x6c4, 0x6c5, 0x5, 0x154, 0xab, 0x2, 0x6c5, 0x6c6, 0x7, 0x69, 0x2, 
       0x2, 0x6c6, 0x6c7, 0x5, 0x120, 0x91, 0x2, 0x6c7, 0x151, 0x3, 0x2, 
       0x2, 0x2, 0x6c8, 0x6c9, 0x5, 0x154, 0xab, 0x2, 0x6c9, 0x6ca, 0x7, 
       0x69, 0x2, 0x2, 0x6ca, 0x6cb, 0x5, 0x120, 0x91, 0x2, 0x6cb, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x6cc, 0x6cd, 0x5, 0x164, 0xb3, 0x2, 0x6cd, 0x6ce, 
       0x7, 0x9a, 0x2, 0x2, 0x6ce, 0x6cf, 0x5, 0x120, 0x91, 0x2, 0x6cf, 
       0x155, 0x3, 0x2, 0x2, 0x2, 0x6d0, 0x6d1, 0x5, 0x158, 0xad, 0x2, 0x6d1, 
       0x6d3, 0x7, 0x5d, 0x2, 0x2, 0x6d2, 0x6d4, 0x7, 0x91, 0x2, 0x2, 0x6d3, 
       0x6d2, 0x3, 0x2, 0x2, 0x2, 0x6d3, 0x6d4, 0x3, 0x2, 0x2, 0x2, 0x6d4, 
       0x6dd, 0x3, 0x2, 0x2, 0x2, 0x6d5, 0x6da, 0x5, 0x120, 0x91, 0x2, 0x6d6, 
       0x6d7, 0x7, 0x63, 0x2, 0x2, 0x6d7, 0x6d9, 0x5, 0x120, 0x91, 0x2, 
       0x6d8, 0x6d6, 0x3, 0x2, 0x2, 0x2, 0x6d9, 0x6dc, 0x3, 0x2, 0x2, 0x2, 
       0x6da, 0x6d8, 0x3, 0x2, 0x2, 0x2, 0x6da, 0x6db, 0x3, 0x2, 0x2, 0x2, 
       0x6db, 0x6de, 0x3, 0x2, 0x2, 0x2, 0x6dc, 0x6da, 0x3, 0x2, 0x2, 0x2, 
       0x6dd, 0x6d5, 0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6de, 0x3, 0x2, 0x2, 0x2, 
       0x6de, 0x6df, 0x3, 0x2, 0x2, 0x2, 0x6df, 0x6e0, 0x7, 0x5e, 0x2, 0x2, 
       0x6e0, 0x157, 0x3, 0x2, 0x2, 0x2, 0x6e1, 0x6e2, 0x5, 0x4, 0x3, 0x2, 
       0x6e2, 0x159, 0x3, 0x2, 0x2, 0x2, 0x6e3, 0x6e4, 0x7, 0x5f, 0x2, 0x2, 
       0x6e4, 0x6e7, 0x5, 0x14e, 0xa8, 0x2, 0x6e5, 0x6e6, 0x7, 0x69, 0x2, 
       0x2, 0x6e6, 0x6e8, 0x5, 0x120, 0x91, 0x2, 0x6e7, 0x6e5, 0x3, 0x2, 
       0x2, 0x2, 0x6e7, 0x6e8, 0x3, 0x2, 0x2, 0x2, 0x6e8, 0x6e9, 0x3, 0x2, 
       0x2, 0x2, 0x6e9, 0x6ea, 0x7, 0x60, 0x2, 0x2, 0x6ea, 0x15b, 0x3, 0x2, 
       0x2, 0x2, 0x6eb, 0x6ef, 0x7, 0x5f, 0x2, 0x2, 0x6ec, 0x6ed, 0x5, 0x164, 
       0xb3, 0x2, 0x6ed, 0x6ee, 0x7, 0x6a, 0x2, 0x2, 0x6ee, 0x6f0, 0x3, 
       0x2, 0x2, 0x2, 0x6ef, 0x6ec, 0x3, 0x2, 0x2, 0x2, 0x6ef, 0x6f0, 0x3, 
       0x2, 0x2, 0x2, 0x6f0, 0x6f1, 0x3, 0x2, 0x2, 0x2, 0x6f1, 0x6f4, 0x5, 
       0x14c, 0xa7, 0x2, 0x6f2, 0x6f3, 0x7, 0xc0, 0x2, 0x2, 0x6f3, 0x6f5, 
       0x5, 0x120, 0x91, 0x2, 0x6f4, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x6f4, 0x6f5, 
       0x3, 0x2, 0x2, 0x2, 0x6f5, 0x6f6, 0x3, 0x2, 0x2, 0x2, 0x6f6, 0x6f7, 
       0x7, 0x69, 0x2, 0x2, 0x6f7, 0x6f8, 0x5, 0x120, 0x91, 0x2, 0x6f8, 
       0x6f9, 0x7, 0x60, 0x2, 0x2, 0x6f9, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x6fa, 
       0x6fb, 0x7, 0x64, 0x2, 0x2, 0x6fb, 0x6fc, 0x5, 0x16e, 0xb8, 0x2, 
       0x6fc, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x6fd, 0x6ff, 0x7, 0x86, 0x2, 0x2, 
       0x6fe, 0x700, 0x5, 0x162, 0xb2, 0x2, 0x6ff, 0x6fe, 0x3, 0x2, 0x2, 
       0x2, 0x700, 0x701, 0x3, 0x2, 0x2, 0x2, 0x701, 0x6ff, 0x3, 0x2, 0x2, 
       0x2, 0x701, 0x702, 0x3, 0x2, 0x2, 0x2, 0x702, 0x70b, 0x3, 0x2, 0x2, 
       0x2, 0x703, 0x704, 0x7, 0x86, 0x2, 0x2, 0x704, 0x706, 0x5, 0x120, 
       0x91, 0x2, 0x705, 0x707, 0x5, 0x162, 0xb2, 0x2, 0x706, 0x705, 0x3, 
       0x2, 0x2, 0x2, 0x707, 0x708, 0x3, 0x2, 0x2, 0x2, 0x708, 0x706, 0x3, 
       0x2, 0x2, 0x2, 0x708, 0x709, 0x3, 0x2, 0x2, 0x2, 0x709, 0x70b, 0x3, 
       0x2, 0x2, 0x2, 0x70a, 0x6fd, 0x3, 0x2, 0x2, 0x2, 0x70a, 0x703, 0x3, 
       0x2, 0x2, 0x2, 0x70b, 0x70e, 0x3, 0x2, 0x2, 0x2, 0x70c, 0x70d, 0x7, 
       0x92, 0x2, 0x2, 0x70d, 0x70f, 0x5, 0x120, 0x91, 0x2, 0x70e, 0x70c, 
       0x3, 0x2, 0x2, 0x2, 0x70e, 0x70f, 0x3, 0x2, 0x2, 0x2, 0x70f, 0x710, 
       0x3, 0x2, 0x2, 0x2, 0x710, 0x711, 0x7, 0x93, 0x2, 0x2, 0x711, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x712, 0x713, 0x7, 0xbf, 0x2, 0x2, 0x713, 0x714, 
       0x5, 0x120, 0x91, 0x2, 0x714, 0x715, 0x7, 0xb8, 0x2, 0x2, 0x715, 
       0x716, 0x5, 0x120, 0x91, 0x2, 0x716, 0x163, 0x3, 0x2, 0x2, 0x2, 0x717, 
       0x718, 0x5, 0x4, 0x3, 0x2, 0x718, 0x165, 0x3, 0x2, 0x2, 0x2, 0x719, 
       0x71c, 0x5, 0x176, 0xbc, 0x2, 0x71a, 0x71c, 0x5, 0x170, 0xb9, 0x2, 
       0x71b, 0x719, 0x3, 0x2, 0x2, 0x2, 0x71b, 0x71a, 0x3, 0x2, 0x2, 0x2, 
       0x71c, 0x167, 0x3, 0x2, 0x2, 0x2, 0x71d, 0x72b, 0x7, 0x61, 0x2, 0x2, 
       0x71e, 0x71f, 0x5, 0x16e, 0xb8, 0x2, 0x71f, 0x720, 0x7, 0x66, 0x2, 
       0x2, 0x720, 0x728, 0x5, 0x120, 0x91, 0x2, 0x721, 0x722, 0x7, 0x63, 
       0x2, 0x2, 0x722, 0x723, 0x5, 0x16e, 0xb8, 0x2, 0x723, 0x724, 0x7, 
       0x66, 0x2, 0x2, 0x724, 0x725, 0x5, 0x120, 0x91, 0x2, 0x725, 0x727, 
       0x3, 0x2, 0x2, 0x2, 0x726, 0x721, 0x3, 0x2, 0x2, 0x2, 0x727, 0x72a, 
       0x3, 0x2, 0x2, 0x2, 0x728, 0x726, 0x3, 0x2, 0x2, 0x2, 0x728, 0x729, 
       0x3, 0x2, 0x2, 0x2, 0x729, 0x72c, 0x3, 0x2, 0x2, 0x2, 0x72a, 0x728, 
       0x3, 0x2, 0x2, 0x2, 0x72b, 0x71e, 0x3, 0x2, 0x2, 0x2, 0x72b, 0x72c, 
       0x3, 0x2, 0x2, 0x2, 0x72c, 0x72d, 0x3, 0x2, 0x2, 0x2, 0x72d, 0x72e, 
       0x7, 0x62, 0x2, 0x2, 0x72e, 0x169, 0x3, 0x2, 0x2, 0x2, 0x72f, 0x732, 
       0x7, 0x68, 0x2, 0x2, 0x730, 0x733, 0x5, 0x4, 0x3, 0x2, 0x731, 0x733, 
       0x7, 0xc6, 0x2, 0x2, 0x732, 0x730, 0x3, 0x2, 0x2, 0x2, 0x732, 0x731, 
       0x3, 0x2, 0x2, 0x2, 0x733, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x734, 0x736, 
       0x5, 0x140, 0xa1, 0x2, 0x735, 0x737, 0x5, 0x15e, 0xb0, 0x2, 0x736, 
       0x735, 0x3, 0x2, 0x2, 0x2, 0x737, 0x738, 0x3, 0x2, 0x2, 0x2, 0x738, 
       0x736, 0x3, 0x2, 0x2, 0x2, 0x738, 0x739, 0x3, 0x2, 0x2, 0x2, 0x739, 
       0x16d, 0x3, 0x2, 0x2, 0x2, 0x73a, 0x73b, 0x5, 0x4, 0x3, 0x2, 0x73b, 
       0x16f, 0x3, 0x2, 0x2, 0x2, 0x73c, 0x73d, 0x9, 0x13, 0x2, 0x2, 0x73d, 
       0x171, 0x3, 0x2, 0x2, 0x2, 0x73e, 0x73f, 0x7, 0x8b, 0x2, 0x2, 0x73f, 
       0x740, 0x7, 0x9b, 0x2, 0x2, 0x740, 0x741, 0x7, 0xa9, 0x2, 0x2, 0x741, 
       0x742, 0x7, 0x66, 0x2, 0x2, 0x742, 0x747, 0x5, 0x11c, 0x8f, 0x2, 
       0x743, 0x744, 0x7, 0x5d, 0x2, 0x2, 0x744, 0x745, 0x5, 0x16e, 0xb8, 
       0x2, 0x745, 0x746, 0x7, 0x5e, 0x2, 0x2, 0x746, 0x748, 0x3, 0x2, 0x2, 
       0x2, 0x747, 0x743, 0x3, 0x2, 0x2, 0x2, 0x747, 0x748, 0x3, 0x2, 0x2, 
       0x2, 0x748, 0x173, 0x3, 0x2, 0x2, 0x2, 0x749, 0x74a, 0x7, 0x1c, 0x2, 
       0x2, 0x74a, 0x74b, 0x7, 0x9b, 0x2, 0x2, 0x74b, 0x74c, 0x7, 0xa9, 
       0x2, 0x2, 0x74c, 0x74d, 0x7, 0x66, 0x2, 0x2, 0x74d, 0x752, 0x5, 0x11c, 
       0x8f, 0x2, 0x74e, 0x74f, 0x7, 0x5d, 0x2, 0x2, 0x74f, 0x750, 0x5, 
       0x16e, 0xb8, 0x2, 0x750, 0x751, 0x7, 0x5e, 0x2, 0x2, 0x751, 0x753, 
       0x3, 0x2, 0x2, 0x2, 0x752, 0x74e, 0x3, 0x2, 0x2, 0x2, 0x752, 0x753, 
       0x3, 0x2, 0x2, 0x2, 0x753, 0x175, 0x3, 0x2, 0x2, 0x2, 0x754, 0x755, 
       0x7, 0xc9, 0x2, 0x2, 0x755, 0x177, 0x3, 0x2, 0x2, 0x2, 0x756, 0x757, 
       0x9, 0x14, 0x2, 0x2, 0x757, 0x179, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x1c8, 
       0x1cd, 0x1e1, 0x1f2, 0x1f9, 0x1fe, 0x20b, 0x215, 0x21a, 0x224, 0x228, 
       0x22c, 0x24c, 0x26c, 0x275, 0x27e, 0x28a, 0x2a7, 0x2b8, 0x2d0, 0x2e0, 
       0x2e3, 0x2f7, 0x30c, 0x314, 0x31c, 0x321, 0x329, 0x32d, 0x339, 0x33c, 
       0x34b, 0x354, 0x35c, 0x365, 0x384, 0x388, 0x3a5, 0x3d2, 0x3dc, 0x3ec, 
       0x3f8, 0x3fc, 0x400, 0x406, 0x40e, 0x411, 0x416, 0x419, 0x41c, 0x427, 
       0x432, 0x43e, 0x447, 0x452, 0x464, 0x467, 0x46f, 0x478, 0x47f, 0x483, 
       0x487, 0x48b, 0x497, 0x49a, 0x49e, 0x4a1, 0x4a8, 0x4b2, 0x4b5, 0x4bd, 
       0x4ca, 0x4ce, 0x4d1, 0x4d4, 0x4db, 0x4e3, 0x4e6, 0x4ed, 0x4f6, 0x501, 
       0x50b, 0x513, 0x51b, 0x522, 0x526, 0x529, 0x52c, 0x536, 0x53e, 0x544, 
       0x54b, 0x54f, 0x559, 0x55c, 0x55f, 0x566, 0x569, 0x56c, 0x570, 0x573, 
       0x579, 0x57c, 0x57f, 0x584, 0x58a, 0x58d, 0x590, 0x59c, 0x59f, 0x5a3, 
       0x5a5, 0x5a9, 0x5af, 0x5b4, 0x5bb, 0x5cc, 0x5d4, 0x5dc, 0x5e2, 0x5eb, 
       0x5f3, 0x5f5, 0x5ff, 0x601, 0x609, 0x60f, 0x618, 0x622, 0x62a, 0x630, 
       0x639, 0x63d, 0x640, 0x644, 0x64a, 0x66c, 0x689, 0x691, 0x69b, 0x69e, 
       0x6b0, 0x6ba, 0x6be, 0x6d3, 0x6da, 0x6dd, 0x6e7, 0x6ef, 0x6f4, 0x701, 
       0x708, 0x70a, 0x70e, 0x71b, 0x728, 0x72b, 0x732, 0x738, 0x747, 0x752, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MemgraphCypher::Initializer MemgraphCypher::_init;
