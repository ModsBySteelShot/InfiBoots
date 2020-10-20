modded class MissionServer
{ 
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		//InfiBoots init
		InfiBootsConfig.GetInstance();
	}
}
