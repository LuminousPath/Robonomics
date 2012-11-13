#pragma once

#include <string>
#include <vector>
#include "Util.h"
#include "Node.h"
#include "Edge.h"

class Graph{
      private:
             std::vector<std::string> nodes;
             std::vector<std::string> edges;
             std::vector<std::string> keys;
             
             std::string getNodes();
             std::string getEdges();
             std::string getKeys();      
      public:
             Graph();
             std::string getGraph();
             std::string getDataKey(std::string keyId, std::string value);
             
             void addKey(std::string keyId, std::string keyFor,std::string attrName, std::string attrType);
             void addNode(std::string nodeId, std::vector<std::string> dataKeys);
             void addEdge(std::string edgeId, std::string target, std::string source, std::string label);
};

const static std::string 
             str_gdef = "<?xml version='1.0' ?><graphml xmlns='http://graphml.graphdrawing.org/xmlns'>",
             str_head = "<graph id='G' edgedefault='directed'>",
             str_foot = "</graph></graphml>",
             
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
