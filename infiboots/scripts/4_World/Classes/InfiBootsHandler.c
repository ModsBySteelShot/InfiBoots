class InfiBootsConfig
{
	private const string CONF_PATH = "$profile:InfiBoots.cfg";
	
	private const float SHOES_MOVEMENT_DAMAGE_PER_STEP = 0;
	
	private static ref InfiBootsConfig instance;
	
	static InfiBootsConfig GetInstance()
	{
		if ( !instance ) 
			instance = new InfiBootsConfig();
		
		return instance;
	}
	
	void InfiBootsConfig()
	{
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
		{
			LoadConfig();
		}
	}
	
	void LoadConfig()
	{
		
	}
	
	void CreateConfig()
	{
		
	}
}