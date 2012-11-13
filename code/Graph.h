#pragma once

#include <string>
#include <vector>
#include "Util.h"
#include "Firm.h"
#include "Structs.h"

static int nodeId = 0;
static int edgeId = 0;
static int keyId = 0;
class Graph{
      private:
             std::vector<ID> nodes;
             std::vector<ID> edges;
             std::vector<ID> keys;
             
             
             std::vector<ID> cycles;
             
             std::string getNodes();
             std::string getEdges();
             std::string getKeys(); 
                 
             int GenerateNodeId();
             int GenerateEdgeId(); 
             int GenerateKeyId(); 
      public:
             Graph();
             
             std::string getGraph();
             std::string getDataKey(std::string keyId, std::string value);
             
             void addKey(std::string keyID, std::string keyFor,std::string attrName, std::string attrType);
             void addNode(std::string dataKeys,std::string prefix);
             void addEdge(std::string target, std::string source, std::string label,std::string prefix);             
             
             void addCycle(int,int);
             void addFirms(int,std::vector<Firm*>);
             void addUnemployed(int,std::vector<Individual*>);
             void addIndividuals(int,Firm*,std::string);
             void buildTrades(int, std::vector<Firm*>);
};


const static std::string 
             str_gdef = "<?xml version='1.0' ?><graphml xmlns='http://graphml.graphdrawing.org/xmlns'>",
             str_head = "<graph id='G' edgedefault='directed'>",
             str_foot = "</graph></graphml>",
             str_nextcycle = "NEXT_CYCLE",
             str_existsin = "EXISTS_IN",
             str_worksfor = "WORKS_FOR",
             str_buysfrom = "BUYS_FROM",
             
             str_datakey = "<data key='%KEY'>%VALUE</data>",
             str_node = "<node id='%NODEID'>%DATAKEYS</node>",
             str_edge = "<edge id='%EDGEID' source='%SOURCE' target='%TARGET' label='%LABEL'/>",
             str_gkey = "<key id='%KEYID' for='%KEYFOR' attr.name='%ATTRNAME' attr.type='%ATTRTYPE'></key>",
             
             str_nodeid = "%NODEID",
             str_datakeys = "%DATAKEYS",
             str_edgeid = "%EDGEID",
             str_source = "%SOURCE",
             str_target = "%TARGET",
             str_label = "%LABEL",
             str_keyid = "%KEYID",
             str_key = "%KEY",
             str_value = "%VALUE",
             str_keyfor = "%KEYFOR",
             str_attrname = "%ATTRNAME",
             str_attrtype = "%ATTRTYPE";
