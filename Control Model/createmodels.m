nlobj = nlmpc(12,12,'MV',[1 2 3 4],'MD',[5]);
nlobj.Ts = 0.5;
nlobj.PredictionHorizon = 10;
nlobj.ControlHorizon = 1;

nlobj.Model.StateFcn = "scalemodelstatefunction";
nlobj.Model.IsContinuousTime = true;
nlobj.Model.NumberOfParameters = 1;

nlobj.Weights.OutputVariables = [0 0 0 0 0 0 0 0 0 0 1 0];

%output variables
nlobj.OutputVariables(3).Min = -1;
nlobj.OutputVariables(3).Max = 1;
nlobj.OutputVariables(6).Min = -1;
nlobj.OutputVariables(6).Max = 1;
nlobj.OutputVariables(7).Min = -0.1;
nlobj.OutputVariables(7).Max = 0.1;
nlobj.OutputVariables(7).MinECR = 0.05;
nlobj.OutputVariables(7).MaxECR = 0.05;
nlobj.OutputVariables(8).Min = -0.3;
nlobj.OutputVariables(8).Max = 0.3;
nlobj.OutputVariables(12).Min = -0.1;
nlobj.OutputVariables(12).Max = 0.1;


nlobj.Weights.ManipulatedVariables = [1, 1, 1, 1];
nlobj.Weights.ManipulatedVariablesRate = [1, 1, 1, 1];

for k = 1:4
    nlobj.ManipulatedVariables(k).Max = 30;
    nlobj.ManipulatedVariables(k).Min = -30;
    nlobj.ManipulatedVariables(k).MaxECR = 0.05;
    nlobj.ManipulatedVariables(k).MinECR = 0.05;
    nlobj.ManipulatedVariables(k).RateMin = -30;
    nlobj.ManipulatedVariables(k).RateMax = 30;
    nlobj.ManipulatedVariables(k).RateMinECR = 2;
    nlobj.ManipulatedVariables(k).RateMaxECR = 2;
end

% nlobj.Optimization.ReplaceStandardCost = true;

nlobj.Optimization.UseSuboptimalSolution = true;

x0 = [0, 0, 0.05, 2, 0, 0.01, 0.02, 0, 0, 0, 0, 0]

mdl = 'scalemodelsimulation';
open_system(mdl)
createParameterBus(nlobj,[mdl '/Controller/Nonlinear MPC Controller'],'myBusObject',{1});