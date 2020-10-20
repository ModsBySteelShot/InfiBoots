/*	
	Copyright(C) 2019-2020 SteelShot <https://github.com/ModsBySteelShot>
	
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#define _ARMA_

class CfgPatches
{
	class InfiBoots
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class InfiBoots
	{
		dir = "InfiBoots";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "InfiBoots";
		credits = "SteelShot";
		author = "SteelShot";
		authorID = "76561198029852322";
		version = "1.0.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"InfiBoots/scripts/3_Game"};
			};
			
			class missionScriptModule
			{
				value = "";
				files[] = {"InfiBoots/scripts/5_Mission"};
			};
		};
	};
};