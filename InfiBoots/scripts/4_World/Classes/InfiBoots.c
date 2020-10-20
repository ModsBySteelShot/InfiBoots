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

class InfiBoots
{
	private static ref InfiBootsConf config;

    static InfiBootsConf GetConf()
    {
        return config;
    }

    static void Init()
    {
        config = new InfiBootsConf();
    }
}

class InfiBootsConf
{
	private const string CONFIG_NAME = "InfiBoots.cfg";

	private const string CONFIG_PATH = "$profile:InfiBoots.cfg"

	private const float SHOES_MOVEMENT_DAMAGE_PER_STEP = 0.035;

	private ref map<string, float> settings;

	private void LoadConfig()
    {
        if (FileExist(CONFIG_PATH))
        {
            FileHandle f = OpenFile(CONFIG_PATH, FileMode.READ);

            for (string line = ""; (FGets(f, line) != -1);)
            {
                TStringArray setting = new TStringArray;
                line.Split("=", setting);

                settings.Set(setting.Get(0), Math.AbsFloat(setting.Get(1).ToFloat()));
            }

            CloseFile(f);

            Print("[InfiBoots] " + CONFIG_NAME + " was found. All values have been loaded.");
        }
        else
        {
            CreateConfig();
        }
    }

	private void CreateConfig()
    {
        FileHandle f = OpenFile(CONFIG_PATH, FileMode.WRITE);

        foreach (string key : settings.GetKeyArray())
        {
            FPrintln(f, key + "=" + settings.Get(key));
        }

        CloseFile(f);

        Print("[InfiBoots] " + CONFIG_NAME + " was not found. Default file created.");
    }

    void InfiBootsConf()
    {
        settings = new map<string, float>;

        settings.Set("SHOES_MOVEMENT_DAMAGE_PER_STEP", SHOES_MOVEMENT_DAMAGE_PER_STEP);

        if (GetGame().IsServer() && GetGame().IsMultiplayer())
        {
            LoadConfig();
        }
    }

    float GetSettingValueByKey(string key)
    {
		return settings.Get(key);
    }
}