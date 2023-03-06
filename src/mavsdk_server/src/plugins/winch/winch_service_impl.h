// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/winch/winch.proto)

#include "winch/winch.grpc.pb.h"
#include "plugins/winch/winch.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename Winch = Winch, typename LazyPlugin = LazyPlugin<Winch>>

class WinchServiceImpl final : public rpc::winch::WinchService::Service {
public:
    WinchServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Winch::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_winch_result = new rpc::winch::WinchResult();
        rpc_winch_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_winch_result->set_result_str(ss.str());

        response->set_allocated_winch_result(rpc_winch_result);
    }

    static rpc::winch::WinchAction
    translateToRpcWinchAction(const mavsdk::Winch::WinchAction& winch_action)
    {
        switch (winch_action) {
            default:
                LogErr() << "Unknown winch_action enum value: " << static_cast<int>(winch_action);
            // FALLTHROUGH
            case mavsdk::Winch::WinchAction::Relaxed:
                return rpc::winch::WINCH_ACTION_RELAXED;
            case mavsdk::Winch::WinchAction::RelativeLengthControl:
                return rpc::winch::WINCH_ACTION_RELATIVE_LENGTH_CONTROL;
            case mavsdk::Winch::WinchAction::RateControl:
                return rpc::winch::WINCH_ACTION_RATE_CONTROL;
            case mavsdk::Winch::WinchAction::Lock:
                return rpc::winch::WINCH_ACTION_LOCK;
            case mavsdk::Winch::WinchAction::Deliver:
                return rpc::winch::WINCH_ACTION_DELIVER;
            case mavsdk::Winch::WinchAction::Hold:
                return rpc::winch::WINCH_ACTION_HOLD;
            case mavsdk::Winch::WinchAction::Retract:
                return rpc::winch::WINCH_ACTION_RETRACT;
            case mavsdk::Winch::WinchAction::LoadLine:
                return rpc::winch::WINCH_ACTION_LOAD_LINE;
            case mavsdk::Winch::WinchAction::AbandonLine:
                return rpc::winch::WINCH_ACTION_ABANDON_LINE;
            case mavsdk::Winch::WinchAction::LoadPayload:
                return rpc::winch::WINCH_ACTION_LOAD_PAYLOAD;
        }
    }

    static mavsdk::Winch::WinchAction
    translateFromRpcWinchAction(const rpc::winch::WinchAction winch_action)
    {
        switch (winch_action) {
            default:
                LogErr() << "Unknown winch_action enum value: " << static_cast<int>(winch_action);
            // FALLTHROUGH
            case rpc::winch::WINCH_ACTION_RELAXED:
                return mavsdk::Winch::WinchAction::Relaxed;
            case rpc::winch::WINCH_ACTION_RELATIVE_LENGTH_CONTROL:
                return mavsdk::Winch::WinchAction::RelativeLengthControl;
            case rpc::winch::WINCH_ACTION_RATE_CONTROL:
                return mavsdk::Winch::WinchAction::RateControl;
            case rpc::winch::WINCH_ACTION_LOCK:
                return mavsdk::Winch::WinchAction::Lock;
            case rpc::winch::WINCH_ACTION_DELIVER:
                return mavsdk::Winch::WinchAction::Deliver;
            case rpc::winch::WINCH_ACTION_HOLD:
                return mavsdk::Winch::WinchAction::Hold;
            case rpc::winch::WINCH_ACTION_RETRACT:
                return mavsdk::Winch::WinchAction::Retract;
            case rpc::winch::WINCH_ACTION_LOAD_LINE:
                return mavsdk::Winch::WinchAction::LoadLine;
            case rpc::winch::WINCH_ACTION_ABANDON_LINE:
                return mavsdk::Winch::WinchAction::AbandonLine;
            case rpc::winch::WINCH_ACTION_LOAD_PAYLOAD:
                return mavsdk::Winch::WinchAction::LoadPayload;
        }
    }

    static std::unique_ptr<rpc::winch::StatusFlags>
    translateToRpcStatusFlags(const mavsdk::Winch::StatusFlags& status_flags)
    {
        auto rpc_obj = std::make_unique<rpc::winch::StatusFlags>();

        rpc_obj->set_healthy(status_flags.healthy);

        rpc_obj->set_fully_retracted(status_flags.fully_retracted);

        rpc_obj->set_moving(status_flags.moving);

        rpc_obj->set_clutch_engaged(status_flags.clutch_engaged);

        rpc_obj->set_locked(status_flags.locked);

        rpc_obj->set_dropping(status_flags.dropping);

        rpc_obj->set_arresting(status_flags.arresting);

        rpc_obj->set_ground_sense(status_flags.ground_sense);

        rpc_obj->set_retracting(status_flags.retracting);

        rpc_obj->set_redeliver(status_flags.redeliver);

        rpc_obj->set_abandon_line(status_flags.abandon_line);

        rpc_obj->set_locking(status_flags.locking);

        rpc_obj->set_load_line(status_flags.load_line);

        rpc_obj->set_load_payload(status_flags.load_payload);

        return rpc_obj;
    }

    static mavsdk::Winch::StatusFlags
    translateFromRpcStatusFlags(const rpc::winch::StatusFlags& status_flags)
    {
        mavsdk::Winch::StatusFlags obj;

        obj.healthy = status_flags.healthy();

        obj.fully_retracted = status_flags.fully_retracted();

        obj.moving = status_flags.moving();

        obj.clutch_engaged = status_flags.clutch_engaged();

        obj.locked = status_flags.locked();

        obj.dropping = status_flags.dropping();

        obj.arresting = status_flags.arresting();

        obj.ground_sense = status_flags.ground_sense();

        obj.retracting = status_flags.retracting();

        obj.redeliver = status_flags.redeliver();

        obj.abandon_line = status_flags.abandon_line();

        obj.locking = status_flags.locking();

        obj.load_line = status_flags.load_line();

        obj.load_payload = status_flags.load_payload();

        return obj;
    }

    static std::unique_ptr<rpc::winch::Status>
    translateToRpcStatus(const mavsdk::Winch::Status& status)
    {
        auto rpc_obj = std::make_unique<rpc::winch::Status>();

        rpc_obj->set_time_usec(status.time_usec);

        rpc_obj->set_line_length_m(status.line_length_m);

        rpc_obj->set_speed_m_s(status.speed_m_s);

        rpc_obj->set_tension_kg(status.tension_kg);

        rpc_obj->set_voltage_v(status.voltage_v);

        rpc_obj->set_current_a(status.current_a);

        rpc_obj->set_temperature_c(status.temperature_c);

        rpc_obj->set_allocated_status_flags(
            translateToRpcStatusFlags(status.status_flags).release());

        return rpc_obj;
    }

    static mavsdk::Winch::Status translateFromRpcStatus(const rpc::winch::Status& status)
    {
        mavsdk::Winch::Status obj;

        obj.time_usec = status.time_usec();

        obj.line_length_m = status.line_length_m();

        obj.speed_m_s = status.speed_m_s();

        obj.tension_kg = status.tension_kg();

        obj.voltage_v = status.voltage_v();

        obj.current_a = status.current_a();

        obj.temperature_c = status.temperature_c();

        obj.status_flags = translateFromRpcStatusFlags(status.status_flags());

        return obj;
    }

    static rpc::winch::WinchResult::Result translateToRpcResult(const mavsdk::Winch::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Winch::Result::Unknown:
                return rpc::winch::WinchResult_Result_RESULT_UNKNOWN;
            case mavsdk::Winch::Result::Success:
                return rpc::winch::WinchResult_Result_RESULT_SUCCESS;
            case mavsdk::Winch::Result::NoSystem:
                return rpc::winch::WinchResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::Winch::Result::Busy:
                return rpc::winch::WinchResult_Result_RESULT_BUSY;
            case mavsdk::Winch::Result::Timeout:
                return rpc::winch::WinchResult_Result_RESULT_TIMEOUT;
            case mavsdk::Winch::Result::Unsupported:
                return rpc::winch::WinchResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::Winch::Result::Failed:
                return rpc::winch::WinchResult_Result_RESULT_FAILED;
        }
    }

    static mavsdk::Winch::Result
    translateFromRpcResult(const rpc::winch::WinchResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::winch::WinchResult_Result_RESULT_UNKNOWN:
                return mavsdk::Winch::Result::Unknown;
            case rpc::winch::WinchResult_Result_RESULT_SUCCESS:
                return mavsdk::Winch::Result::Success;
            case rpc::winch::WinchResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::Winch::Result::NoSystem;
            case rpc::winch::WinchResult_Result_RESULT_BUSY:
                return mavsdk::Winch::Result::Busy;
            case rpc::winch::WinchResult_Result_RESULT_TIMEOUT:
                return mavsdk::Winch::Result::Timeout;
            case rpc::winch::WinchResult_Result_RESULT_UNSUPPORTED:
                return mavsdk::Winch::Result::Unsupported;
            case rpc::winch::WinchResult_Result_RESULT_FAILED:
                return mavsdk::Winch::Result::Failed;
        }
    }

    grpc::Status SubscribeStatus(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::winch::SubscribeStatusRequest* /* request */,
        grpc::ServerWriter<rpc::winch::StatusResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        const mavsdk::Winch::StatusHandle handle = _lazy_plugin.maybe_plugin()->subscribe_status(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex, &handle](
                const mavsdk::Winch::Status status) {
                rpc::winch::StatusResponse rpc_response;

                rpc_response.set_allocated_status(translateToRpcStatus(status).release());

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _lazy_plugin.maybe_plugin()->unsubscribe_status(handle);

                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status Relax(
        grpc::ServerContext* /* context */,
        const rpc::winch::RelaxRequest* request,
        rpc::winch::RelaxResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Relax sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->relax(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status RelativeLengthControl(
        grpc::ServerContext* /* context */,
        const rpc::winch::RelativeLengthControlRequest* request,
        rpc::winch::RelativeLengthControlResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RelativeLengthControl sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->relative_length_control(
            request->instance(), request->length_m(), request->rate_m_s());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status RateControl(
        grpc::ServerContext* /* context */,
        const rpc::winch::RateControlRequest* request,
        rpc::winch::RateControlResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RateControl sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result =
            _lazy_plugin.maybe_plugin()->rate_control(request->instance(), request->rate_m_s());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status Lock(
        grpc::ServerContext* /* context */,
        const rpc::winch::LockRequest* request,
        rpc::winch::LockResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Lock sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->lock(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status Deliver(
        grpc::ServerContext* /* context */,
        const rpc::winch::DeliverRequest* request,
        rpc::winch::DeliverResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Deliver sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->deliver(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status Hold(
        grpc::ServerContext* /* context */,
        const rpc::winch::HoldRequest* request,
        rpc::winch::HoldResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Hold sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->hold(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status Retract(
        grpc::ServerContext* /* context */,
        const rpc::winch::RetractRequest* request,
        rpc::winch::RetractResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "Retract sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->retract(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status LoadLine(
        grpc::ServerContext* /* context */,
        const rpc::winch::LoadLineRequest* request,
        rpc::winch::LoadLineResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "LoadLine sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->load_line(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status AbandonLine(
        grpc::ServerContext* /* context */,
        const rpc::winch::AbandonLineRequest* request,
        rpc::winch::AbandonLineResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "AbandonLine sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->abandon_line(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status LoadPayload(
        grpc::ServerContext* /* context */,
        const rpc::winch::LoadPayloadRequest* request,
        rpc::winch::LoadPayloadResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Winch::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "LoadPayload sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->load_payload(request->instance());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk