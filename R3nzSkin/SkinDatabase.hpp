#pragma once

#include <cstdint>
#include <map>
#include <utility>
#include <vector>

#include "fnv_hash.hpp"

class SkinDatabase {
public:
	class skin_info {
	public:
		const char* model_name;
		std::string skin_name;
		std::int32_t skin_id;
	};

	class jungle_mob_skin_info {
	public:
		const char* name;
		std::vector<std::uint64_t> name_hashes;
		std::vector<const char*> skins;
	};

	class specialSkin {
	public:
		std::uint64_t champHash;
		std::int32_t skinIdStart;
		std::int32_t skinIdEnd;
		std::vector<const char*> gears;
	};

	void load() noexcept;

	std::map<std::uint64_t, std::vector<skin_info>> champions_skins;
	std::vector<std::pair<std::uint32_t, const char*>> wards_skins;

	std::vector<const char*> minions_skins{
		"Minion", "Summer Minion",
		"Project Minion", "Snowdown Minion",
		"Draven Minion", "Star Guardian Minion",
		"Arcade Minion", "Snowdown 2 Minion",
		"Odyssey Minion", "Mouse Minion", "Arcane Minion"
	};

	std::vector<const char*> turret_skins{
		"Default Order Turret", "Default Chaos Turret",
		"Snow Order Turret", "Snow Chaos Turret",
		"Twisted Treeline Order Turret", "Twisted Treeline Chaos Turret",
		"URF Order Turret", "URF Chaos Turret",
		"Arcade Turret",
		"Temple of Lily and Lotus Turret",
		"Arcane Order Turret", "Arcane Chaos Turret",
		"Butcher's Bridge Order Turret", "Butcher's Bridge Chaos Turret",
		"Howling Abyss Order Turret", "Howling Abyss Chaos Turret"
	};

	std::vector<jungle_mob_skin_info> jungle_mobs_skins{
		{
			"纳什男爵",
			{ FNV("SRU_Baron") },
			{ "Baron", "Snowdown Baron", "Championship Baron", "Lunar Revel Baron", "MSI Baron", "Odyssey Baron", "Championship Birthday Baron", "Ruined King Baron" }
		},
		{
			"苍蓝雕纹魔像",
			{ FNV("SRU_Blue") },
			{ "Blue", "Dark Blue", "Pool Party Blue", "Ruined King Blue" }
		},
		{
			"绯红印记树怪",
			{ FNV("SRU_Red") },
			{ "Red", "Pool Party Red", "Ruined King Red" }
		},
		{
			"峡谷迅捷蟹",
			{ FNV("Sru_Crab") },
			{ "Scuttle", "Halloween Light Scuttle", "Halloween Dark Scuttle", "Ruined King Scuttle" }
		},
		{
			"石甲虫",
			{ FNV("SRU_Krug"), FNV("SRU_KrugMini"), FNV("SRU_KrugMiniMini") },
			{ "Krug", "Dark Krug" }
		},
		{
			"深红锋喙鸟",
			{ FNV("SRU_Razorbeak"), FNV("SRU_RazorbeakMini") },
			{ "Razorbeak", "Chicken Razorbeak" }
		}
	};

	std::vector<specialSkin> specialSkins{
		{ FNV("Katarina"), 29, 36, { "匕首1", "匕首2", "匕首3", "匕首4", "匕首 5", "匕首6" }},
		{ FNV("Renekton"), 26, 32, { "无头盔", "头盔", "鳍片", "终极" } },
		{ FNV("MissFortune"), 16, 16, { "血色女王", "总攻时刻", "皇家武装", "星辰虫群" } },
		{ FNV("Ezreal"), 5, 5, { "等级1", "等级2", "等级3" } }
	};
};
