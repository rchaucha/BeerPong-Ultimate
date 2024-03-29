#pragma once

#include <memory>
#include <map>
#include <algorithm>
#include <set>
#include <QRectF>

#include "../glasses/AGlass.hpp"


typedef unsigned long GlassID;

struct CircleInGroup
{
   GroupID group_id = 0;
   QRectF rect;
};


class GameMode
{
public:
   virtual std::string get_name() = 0;
   virtual std::string get_description() = 0;

   virtual void update_logic(std::map<GlassID, QRectF>& circles) = 0;
   virtual void update_view() = 0;

   virtual bool are_players_used() = 0;
   virtual bool are_points_glasses_used() = 0;

   void set_players(std::set<Player>&& players);
   void set_points(std::set<Points>&& points);

   std::vector<CircleInGroup> get_glasses() const;

protected:
   GameMode() = default;

   std::map<GlassID, std::unique_ptr<AGlass>> _glasses;
   std::set<Player> _players;
   std::set<Points> _points;

   GlassGroupIDManager* _group_id_manager = nullptr;
};
